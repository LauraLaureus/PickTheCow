#include <stdio.h>
#define _USE_MATH_DEFINES
#include <cmath>


#include <GLUT/GLUT.h>
#include "Test.h"
#include "Game.h"
#include "TestGame.h"
#include "EuclideanDistance.h"
#include "LaserTableSpace.h"
#include "LaserManager.hpp"
#include "Connection_information.h"

#include <iostream>

#define WINDOW_ANCHO 1280
#define WINDOW_ALTO 720

// Espacio para las variables globales de la ventana
float gl_fovy = 15.0f;
float gl_fovy_min = 5.0f, gl_fovy_max = 90.0f, gl_fovy_paso = 1.0f;
float gl_cerca = 0.01f, gl_lejos = 100.0f;
float gl_center = 10.0f; // centro donde pondremos los objetos


// Espacio para otras variables globales
double theta = M_PI_2, phi = 0.0;
double radio = 7.0;

/*********************************************/
/*********************************************/
// Estas Variables me dicen donde están el usuario (Las actualiza el Laser o el Teclado)
int currentUserRow = 0;
int currentUserColumn = 0; 
double currentX = 99;
double currentY = 99;

// Dimensiones del Tablero
int numberOfTableRows = 4;
int numberOfTableColumns = 3;
int numberOfSubRowsPerTableCell = 3;
int numberOfSubColumnsPerTableCell = 3;
int MAX_SUBROW = numberOfTableRows * numberOfSubRowsPerTableCell;
int MAX_SUBCOLUMN = numberOfTableColumns * numberOfSubColumnsPerTableCell;

//TIMER_PERIOD: Debe ser el período más bajo, el resto de períodos deben ser un múltiplo de este.
int TIMER_PERIOD = 10;
const int FALLINGOBJECT_CREATION_PERIOD = TIMER_PERIOD * 100;	// Para crear Objetos que caen
const int FALLINGOBJECT_UPDATING_PERIOD = TIMER_PERIOD * 10/5;	// Para actualizar Posición de Objetos que caen
const int HANDLE_SCENE_PERIOD = TIMER_PERIOD * 1;				// Para gestionar posición de usuario y, ver si objeto que cae es cogido por Usuario o desaparece en el suelo
int FALLINGOBJECT_CREATION_COUNTER = 0;
int FALLINGOBJECT_UPDATING_COUNTER = 0;
int HANDLE_SCENE_COUNTER = 0;

bool lock = false;
TestGame* testGame;

void dibujaEsfera(float x, float y, float z, float r);
void test1();
void initGame();
void Teclado(unsigned char key, int x, int y);
void Timer(int v);
/*********************************************/
/*********************************************/


// Espacio para la declaraci�n de funciones

void InitGL();
void Display();
void ReshapeSize(int ancho, int alto);
void PosicionRaton(int x, int y);
void RuedaRaton(int rueda, int sentido, int x, int y);


//main
int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINDOW_ANCHO, WINDOW_ALTO);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("OpenGL Practica ");
	
	InitGL();
	glutDisplayFunc(Display); // registra la funcion de rendering 
	glutReshapeFunc(ReshapeSize);
	glutMotionFunc(PosicionRaton);
	

	initGame();
	glutTimerFunc(TIMER_PERIOD, Timer, 0);
	glutKeyboardFunc(Teclado);

    if(!LaserManager::open()) exit(1);
    LaserManager::setWorkSpaceVertex(700, 2000, 1000, 50);
    
	glutMainLoop(); // bucle principal

	return 0;
}


void setViewport() {
	int ancho = glutGet(GLUT_WINDOW_WIDTH);
	int alto = glutGet(GLUT_WINDOW_HEIGHT);
	glViewport(0, 0, ancho, alto); // utiliza la totalidad de la ventana
}

void setProjection() {
	int ancho = glutGet(GLUT_WINDOW_WIDTH);
	int alto = glutGet(GLUT_WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(gl_fovy, (float)ancho / (float)alto, gl_cerca, gl_lejos);
}

void setModelView() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void setLight0() {

	float ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	//float diffuse[4] = { 1.0f,1.0f,1.0f,1.0f };
	//float specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float diffuse[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float specular[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
	

	float position[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float direction[4] = { -1.0f, -1.0f, -1.0f, 1.0f };
	float cut_off = 90.0f;

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cut_off);

	glEnable(GL_LIGHT0);
}



void InitGL() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	// para cambiar el criterio de lo que se ve. 
	// LESS es el de defecto: se ve lo que tiene menor profundidad 
	glDepthFunc(GL_LESS);
	// TO DO

	setViewport();
	setProjection();

	glEnable(GL_LIGHTING);
	//glShadeModel(GL_FLAT);
	glShadeModel(GL_SMOOTH);

	setLight0();
}

// cambio de dimensiones de la ventana, manteniendo la dimension de los objetos
void ReshapeSize(int ancho, int alto) {

	setViewport();
	setProjection();
	glutPostRedisplay();
}

void PosicionRaton(int x, int y) {

	int ancho = glutGet(GLUT_WINDOW_WIDTH);
	int alto = glutGet(GLUT_WINDOW_HEIGHT);

	theta = M_PI*(double)y / (double)alto;
	phi = -M_PI + 2 * M_PI * (double)x / (double)ancho;
	glutPostRedisplay();
}

void RuedaRaton(int rueda, int sentido, int x, int y) {

	gl_fovy -= gl_fovy_paso*(float)sentido;
	if (gl_fovy < gl_fovy_min) gl_fovy = gl_fovy_min;
	if (gl_fovy > gl_fovy_max) gl_fovy = gl_fovy_max;
	setProjection();
	glutPostRedisplay();
}

void setMaterial() {

	const GLfloat ambient[4] = { 0.2f, 0.0f, 0.0f, 1.0f };
	const GLfloat diffuse[4] = { 0.7f, 0.0f, 0.0f, 1.0f };
	const GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat shininess = 100.0f;


	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}


void setMaterial2() {
	const GLfloat ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	const GLfloat diffuse[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
	const GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat shininess = 100.0f;


	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void setMaterial3() {
	const GLfloat ambient[4] = { 0.0f, 0.0f, 0.2f, 1.0f };
	const GLfloat diffuse[4] = { 0.0f, 0.0f, 0.7f, 1.0f };
	const GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat shininess = 100.0f;


	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void setMaterial4() {
	const GLfloat ambient[4] = { 0.0f, 0.2f, 0.0f, 1.0f };
	const GLfloat diffuse[4] = { 0.0f, 0.7f, 0.0f, 1.0f };
	const GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat shininess = 100.0f;


	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

// función de gestión de ventana
void Display() {
	if (!lock) {
		lock = true;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra todo lo existente en el framebuffer
		setModelView();

		// poicionamos el centro de coordenadas 
		glTranslatef(-4.2f, -2.0f, -gl_center);

		// el eje cenital es el Y
		float x = (float)(radio*sin(theta)*sin(phi))*-2;
		float y = (float)(radio*cos(theta));
		float z = (float)(radio*sin(theta)*cos(phi));
		gluLookAt(x, y, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // mira al (0,0,0)

		setMaterial();
		// TO DO

		/*dibujaEsfera(0.0f, 0.0f, 0.0f, 0.1f);
		dibujaEsfera(1.0f, 0.0f, 0.0f, 0.1f);
		dibujaEsfera(0.0f, 1.0f, 0.0f, 0.1f);
		dibujaEsfera(1.0f, 1.0f, 0.0f, 0.1f);
		dibujaEsfera(0.0f, 0.0f, -1.0f, 0.1f);
		dibujaEsfera(1.0f, 0.0f, -1.0f, 0.1f);
		dibujaEsfera(0.0f, 1.0f, -1.0f, 0.1f);
		dibujaEsfera(1.0f, 1.0f, -1.0f, 0.1f);*/

		//test1();
		testGame->display();

		glFlush(); // actualiza el framebuffer
		glutSwapBuffers(); // en caso de animacion

		lock = false;
	}
}

void dibujaEsfera(float x, float y, float z, float r) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glutWireSphere(r, 10, 10);
	glPopMatrix();
}

void test1() {
	double positionX = 5.0;
	double positionY = 5.0;
	double positionZ = 5.0;
	int numberOfRows = 8;
	int numberOfColumns = 8;
	double squareHeight = 0.5;
	double squareWidth = 0.5;
	RGBColor cellColor1 = RGBColor(0.2f, 0.0f, 0.0f, 3.0f);
	RGBColor cellColor2 = RGBColor(0.0f, 0.2f, 0.0f, 3.0f);
	RGBColor homeColor = RGBColor(0.0f, 0.0f, 0.2f, 3.0f);
	double scaleFactor = 1;
	bool home = true;

	//glutWireTeapot(1);

	Test test = Test();
	//test.drawTableXY(positionX, positionY, positionZ, numberOfRows, numberOfColumns, squareHeight, squareWidth, cellColor1, cellColor2, homeColor, home);
	test.drawRoomXY(positionX, positionY, positionZ, numberOfRows, numberOfColumns, squareHeight, squareWidth, cellColor1, cellColor2, homeColor);
	test.drawModeledObject(positionX, positionY, positionZ, "ModeledObjectFiles/cow.ply", cellColor2, scaleFactor);
	test.drawScore(positionX, positionY, positionZ, 10, GLUT_BITMAP_TIMES_ROMAN_24, cellColor1);
}

void initGame() {

	// Definición del GameArea
    double left = -700;
	double right = 1000;
    double bottom = 5;
	double top = 2000;
	
	int numberOfRows = numberOfTableRows;
	int numberOfColumns = numberOfTableColumns;
	int numberOfSubRows = numberOfSubRowsPerTableCell;
	int numberOfSubColumns = numberOfSubColumnsPerTableCell;
	
	// Definición del Cubo
	double positionX = 0.0;
	double positionY = 0.0;
	double positionZ = 0.0;
	double tableCellHeight = 3.0;
	double tableCellWidth = 3.0;
	RGBColor cellColor1 = RGBColor(0.9f, 0.9f, 0.9f, 3.0f);
	RGBColor cellColor2 = RGBColor(0.9f, 0.2f, 0.0f, 3.0f);
	RGBColor homeColor = RGBColor(0.0f, 0.8f, 0.8f, 3.0f);

	// Definición de Objetos que caen
	unsigned int maximunQuantity = 4;							// Máximo número de Objetos que pueden caer al mismo tiempo
	int creationPeriod = FALLINGOBJECT_CREATION_PERIOD;			// Cada cuánto se crea un nuevo Objeto que cae
	int positionUpdatingPeriod = FALLINGOBJECT_UPDATING_PERIOD;	// Cada cuánto se despplaza el Objeto que cae
	double fallingDistanceIncrement = 0.1;						// Cuánto se desplaza el objeto que cae cade vez que lo hace 
	double minimunDistanceToFloor = 0.001;						// Distancia al suelo antes de que desaparezca

	// Definición del Usuario
	double maxCatchDistance = 2;
	int userLaserRow = 10;
	int userLaserColumn = 10;
	char* userFileName = "/Users/lala/definitivo/GetTheBall/GetTheBall/ModeledObjectFiles/cow.ply";
	RGBColor userColor = RGBColor(0.0f, 0.2f, 0.0f, 3.0f);
	double userScaleFactor = 0.1;

	double scoreX = 6.3;
	double scoreY = 3.2;
	double scoreZ = 5.0;
	RGBColor scoreColor = RGBColor(0.0f, 0.2f, 0.0f, 3.0f);
	void* font = GLUT_BITMAP_TIMES_ROMAN_24;

	testGame = new TestGame(left, right,bottom, top, numberOfRows, numberOfColumns, numberOfSubRows, numberOfSubColumns, tableCellHeight, tableCellWidth,
		positionX, positionY, positionZ,
		cellColor1, cellColor2, homeColor,
		maximunQuantity, creationPeriod, positionUpdatingPeriod, fallingDistanceIncrement, minimunDistanceToFloor,
		maxCatchDistance, userLaserRow, userLaserColumn, userFileName, userColor, userScaleFactor,
		scoreX, scoreY, scoreZ, scoreColor, font);

	testGame->display();
}

void Timer(int v) {

	//std::cout << "Entrando en Timer\n";
	if (!lock) {
		lock = true;

		bool reDisplay = false;

		HANDLE_SCENE_COUNTER++;
		FALLINGOBJECT_UPDATING_COUNTER++;
		FALLINGOBJECT_CREATION_COUNTER++;

		if (HANDLE_SCENE_PERIOD / TIMER_PERIOD == HANDLE_SCENE_COUNTER) {
			PlanePoint p = LaserManager::readLaser();
			currentX = p.x;
			currentY = p.y;
            printf("X: %f Y: %f \n", currentX,currentY);
			//std::cout << "Entrando en HANDLE_SCENE_PERIOD\n";
			testGame->handleFallingObjects();
			//testGame->updateUserPositionBySubCell(currentUserRow, currentUserColumn);
			testGame->updateUserPositionByPoint(currentX, currentY);
			reDisplay = true;
			HANDLE_SCENE_COUNTER = 0;
		}

		if (FALLINGOBJECT_UPDATING_PERIOD / TIMER_PERIOD == FALLINGOBJECT_UPDATING_COUNTER) {
			//std::cout << "Entrando en FALLINGOBJECT_UPDATE_PERIOD\n";
			testGame->updateFallingObjectsPosition();
			reDisplay = true;
			FALLINGOBJECT_UPDATING_COUNTER = 0;
		}

		if (FALLINGOBJECT_CREATION_PERIOD / TIMER_PERIOD == FALLINGOBJECT_CREATION_COUNTER) {
			//std::cout << "Entrando en FALLINGOBJECT_CREATION_PERIOD\n";
			testGame->createNewFallingObject();
			reDisplay = true;
			FALLINGOBJECT_CREATION_COUNTER = 0;
		}

		if (reDisplay) {
			glutPostRedisplay();
		}

		lock = false;
	}
	
	glutTimerFunc(TIMER_PERIOD, Timer, v);
}

void Teclado(unsigned char key, int x, int y) {

	switch (key) {
	case 'q':
		currentUserRow = currentUserRow < MAX_SUBROW - 1 ? currentUserRow + 1 : currentUserRow;
		break;
	case 'a':
		currentUserRow = currentUserRow > 0 ? currentUserRow - 1 : currentUserRow;
		break;
	case 'o':
		currentUserColumn = currentUserColumn > 0 ? currentUserColumn - 1 : currentUserColumn;
		break;
	case 'p':
		currentUserColumn = currentUserColumn < MAX_SUBCOLUMN - 1 ? currentUserColumn + 1 : currentUserColumn;
		break;
	}

	//glutPostRedisplay(); // De decir cuando se pinta  se encarga el Timer, ...
}
