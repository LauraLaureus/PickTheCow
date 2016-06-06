#include "TestGame.h"

#include <iostream>
#include <time.h>

#include "RGBColor.h"
#include "OGLTableXY.h"
#include "OGLRoomXY.h"
#include "OGLModeledObject.h"
#include "OGLScore.h"

#include "Model_PLY.h"

#include "Coordinates3DCalculation.h"
#include "TableXPosZNegSquareVertex3DCoordinatesCalculation.h"

TestGame::TestGame(double left, double right, double bottom, double top, int numberOfRows, int numberOfColumns, int numberOfSubRows, int numberOfSubColumns, double tableCellHeight, double tableCellWidth,
	double positionX, double positionY, double positionZ,
	RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor,
	unsigned int maximunQuantity, int creationPeriod, int positionUpdatingPeriod, double fallingDistanceIncrement, double minimunDistanceToFloor,
	double maxCatchDistance, int userLaserRow, int userLaserColumn, char* userFileName, RGBColor userColor, double userScaleFactor,
	double scoreX, double scoreY, double scoreZ, RGBColor scoreColor, void* font) {
	Coordinates3D position0 = Coordinates3D(0.0, 0.0, 0.0);
	bool home = true;

	TableXYLightAndColorAttributes tableXYLightAndColorAttributes = TableXYLightAndColorAttributes(cellColor1, cellColor2, homeColor);
	OGLTableXY* floor = new OGLTableXY(position0, numberOfRows, numberOfColumns, tableCellHeight, tableCellWidth, home, tableXYLightAndColorAttributes);
	OGLTableXY* ceiling = new OGLTableXY(position0, numberOfRows, numberOfColumns, tableCellHeight, tableCellWidth, !home, tableXYLightAndColorAttributes);
	OGLTableXY* backWall = new OGLTableXY(position0, numberOfRows, numberOfColumns, tableCellHeight, tableCellWidth, !home, tableXYLightAndColorAttributes);
	OGLTableXY* leftWall = new OGLTableXY(position0, numberOfRows, numberOfColumns, tableCellHeight, tableCellWidth, !home, tableXYLightAndColorAttributes);
	OGLTableXY* rightWall = new OGLTableXY(position0, numberOfRows, numberOfColumns, tableCellHeight, tableCellWidth, !home, tableXYLightAndColorAttributes);

	Coordinates3D position = Coordinates3D(positionX, positionY, positionZ);
	RoomXYLightAndColorAttributes roomXYLightAndColorAttributes = RoomXYLightAndColorAttributes();
	OGLRoomXY* roomXY = new OGLRoomXY(position, *floor, *ceiling, *backWall, *leftWall, *rightWall, roomXYLightAndColorAttributes);
	
	Coordinates3D userPosition = position0;
	Model_PLY* model_PLY = new Model_PLY();
	model_PLY->Load(userFileName);
	ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes = ModeledObjectLightAndColorAttributes(userColor);
	OGLModeledObject* userModeledObject = new OGLModeledObject(userPosition, model_PLY, modeledObjectLightAndColorAttributes, userScaleFactor);
	User* user = new User(*userModeledObject, maxCatchDistance);
	
	ScoreLightAndColorAttributes scoreLightAndColorAttributes = ScoreLightAndColorAttributes(scoreColor);
	Coordinates3D scorePosition = Coordinates3D(scoreX, scoreY, scoreZ);
	int initialScore = 0;
	OGLScore* score = new OGLScore(scorePosition, initialScore, font, scoreLightAndColorAttributes);
	
	Scene* scene = new Scene(*roomXY, *user, *score);

	FallingObjectsProperties* fallingObjectsProperties = new FallingObjectsProperties(maximunQuantity, creationPeriod, positionUpdatingPeriod, fallingDistanceIncrement, minimunDistanceToFloor);

	int inititalGameMode = Game::GAMEMODE_PLAYING;

	gameArea = new GameArea(left, right,bottom,  top, numberOfRows, numberOfColumns, numberOfSubRows, numberOfSubColumns, tableCellHeight, tableCellWidth, position);
	game = new Game(*scene, inititalGameMode, *fallingObjectsProperties, *gameArea);

	fallingObjectsHandling = new FallingObjectsHandling(*game);
	fallingObjectsPositionUpdating = new FallingObjectsPositionUpdating(*game);
	newFallingObjectCreation = new NewFallingObjectCreation(*game);
	userPositionUpdating = new UserPositionUpdating(*game);

	init();
}


TestGame::~TestGame()
{
	delete gameArea;
	delete fallingObjectsHandling;
	delete fallingObjectsPositionUpdating;
	delete newFallingObjectCreation;
	delete userPositionUpdating;

	delete game;
	delete fallingObjectsProperties;
	delete scene;
	delete score;
	delete user;
	delete userModeledObject;
	delete model_PLY;
	delete roomXY;
	delete right;
	delete left;
	delete back;
	delete ceiling;
	delete floor;


	//std::list<FallingObject*>* fallingObjects = game->getScene().getFallingObjects();
	//for (std::list<FallingObject*>::iterator fallingObject = fallingObjects->begin(); fallingObject != fallingObjects->end(); ++fallingObject) {
	//	delete *fallingObject;
	//}
}

Game* TestGame::getGame() {
	return game;
}

void TestGame::init() {
	this->userPositionUpdating->updateUserPositionByCell(1, 1);
}

void TestGame::display() {

	//game->drawScene();

	Scene scene = game->getScene();

	scene.getRoomXY().draw();
	scene.getUser().getObject3D().draw();

	std::list<FallingObject*> fallingObjects = scene.getFallingObjects();
	for (std::list<FallingObject*>::iterator fallingObject = fallingObjects.begin(); fallingObject != fallingObjects.end(); ++fallingObject) {
		Object3D* object3D = (*fallingObject)->getObject3D();
		object3D->draw();

		highligthTableCell((*fallingObject)->getObject3D()->getPosition());
	}

	scene.getScore().draw();
}

FallingObject* TestGame::getNewFallingObject() {

	// Define constantes
	const int scorePointsVector[numberOfFallingObjects] = { 10, 20, 30 };	
	//char* modeledObjectNamesVector[numberOfFallingObjects] = { "ModeledObjectFiles/bun_zipper.ply", "ModeledObjectFiles/bun_zipper.ply", "ModeledObjectFiles/bun_zipper.ply" };
	//double modeledObjectScaleFactorsVector[numberOfFallingObjects] = { 1, 1, 1 };
	char* modeledObjectNamesVector[numberOfFallingObjects] = { "/Users/lala/definitivo/GetTheBall/GetTheBall/ModeledObjectFiles/cow.ply", "/Users/lala/definitivo/GetTheBall/GetTheBall/ModeledObjectFiles/cow.ply", "/Users/lala/definitivo/GetTheBall/GetTheBall/ModeledObjectFiles/cow.ply" };
	double modeledObjectScaleFactorsVector[numberOfFallingObjects] = { 0.1, 0.1, 0.1 };
	const RGBColor colorsVector[numberOfColors] = { RGBColor(1, 0, 0, 1), RGBColor(0, 1, 0, 1), RGBColor(0, 0, 1, 1), RGBColor(1, 0, 1, 1) };
	
	srand((unsigned int)time(NULL));
	
	int scoreIndex = rand() % numberOfFallingObjects;
	int modeledObjectNameIndex = rand() % numberOfFallingObjects;
	int modeledObjectScaleFactorIndex = rand() % numberOfFallingObjects;
	int colorIndex = rand() % numberOfColors;
	
	GameArea gameArea = game->getGameArea();
	int rowIndex = 1 + rand() % (game->getGameArea().getNumberOfRows() - 1);
	int columnIndex = rand() % gameArea.getNumberOfColumns();

    
	RoomXY& roomXY = game->getScene().getRoomXY();
	Coordinates3D roomPosition = roomXY.getPosition();
	Coordinates3D relativePosition = Coordinates3DCalculation(rowIndex, columnIndex, gameArea, roomPosition.getY() + roomXY.getHeight()).executeByCells();
	Coordinates3D position = Coordinates3D(
			roomPosition.getX() + relativePosition.getX(),
			roomPosition.getY() + relativePosition.getY(),
			roomPosition.getZ() + relativePosition.getZ());
	
	Model_PLY *model_PLY = new Model_PLY();
	model_PLY->Load(modeledObjectNamesVector[modeledObjectNameIndex]);
	ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes = ModeledObjectLightAndColorAttributes(colorsVector[colorIndex]);
	OGLModeledObject* newObject3D = new OGLModeledObject(position, model_PLY, modeledObjectLightAndColorAttributes, modeledObjectScaleFactorsVector[modeledObjectScaleFactorIndex]);
	
	return new FallingObject(newObject3D, scorePointsVector[scoreIndex], rowIndex, columnIndex);
	return 0;
}

void TestGame::handleFallingObjects() {
	fallingObjectsHandling->execute();
}

void TestGame::updateFallingObjectsPosition() {
	fallingObjectsPositionUpdating->execute();
}

void TestGame::createNewFallingObject() {
	FallingObject* fallingObject = getNewFallingObject();
	Coordinates3D position = fallingObject->getObject3D()->getPosition();
	//std::cout << "Creando Objeto con Pos: (" << position.getX() << ", " << position.getY() << ", " << position.getZ() << ")\n";
	newFallingObjectCreation->execute(fallingObject);
}

void TestGame::updateUserPositionByCell(int rowIndex, int columnIndex) {
	this->userPositionUpdating->updateUserPositionByCell(rowIndex, columnIndex);
}

void TestGame::updateUserPositionBySubCell(int subRowIndex, int subColumnIndex) {
	this->userPositionUpdating->updateUserPositionBySubCell(subRowIndex, subColumnIndex);
}

void TestGame::updateUserPositionByPoint(int x, int y) {
	this->userPositionUpdating->updateUserPositionByPoint(x, y);
}

void TestGame::highligthTableCell(Coordinates3D position) {
	//GameArea gameArea = game->getGameArea();
	//int columnIndex = gameArea.getColumnIndexFromVirtualWorld(position.getX());
	//int rowIndex = gameArea.getRowIndexFromVirtualWorld(position.getZ());
	//TableXY& floor = game->getScene().getRoomXY().getFloor();
	//Coordinates3D* c0 = TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex0(floor, rowIndex, columnIndex);
	//Coordinates3D* c1 = TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex1(floor, rowIndex, columnIndex);
	//Coordinates3D* c2 = TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex2(floor, rowIndex, columnIndex);
	//Coordinates3D* c3 = TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex3(floor, rowIndex, columnIndex);
	//OGLTableXY::drawTableCell(c0, c1, c2, c3, color, tableXYLightAndColorAttributes);
	//delete c0;
	//delete c1;
	//delete c2;
	//delete c3;
	//será el mismo procesom para saber fila y columna de usuario
}
