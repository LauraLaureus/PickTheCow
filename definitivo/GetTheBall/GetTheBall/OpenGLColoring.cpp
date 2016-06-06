#include "OpenGLColoring.h"

#include <GLUT/GLUT.h>
void OpenGLColoring::setMaterialColor(float red,float green,float blue,float diffuseFactor) {
	const GLfloat ambient[4] = { red, green, blue, 1.0f };
	const GLfloat diffuse[4] = { red*diffuseFactor, green*diffuseFactor, blue*diffuseFactor, 1.0f };
	const GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat shininess = 100.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
