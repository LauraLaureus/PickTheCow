#include "OGLRoomXY.h"

#include <GLUT/GLUT.h>
OGLRoomXY::OGLRoomXY(Coordinates3D position, TableXY& floor, TableXY& ceiling, TableXY& leftWall, TableXY& rightWall, TableXY& backWall, RoomXYLightAndColorAttributes roomXYLightAndColorAttributes)
	: RoomXY (position, floor, ceiling, leftWall, rightWall, backWall),
	roomXYLightAndColorAttributes(roomXYLightAndColorAttributes) {
}


OGLRoomXY::~OGLRoomXY() {
}

RoomXYLightAndColorAttributes OGLRoomXY::getRoomXYLightAndColorAttributes() {
	return roomXYLightAndColorAttributes;
}

void OGLRoomXY::setRoomXYLightAndColorAttributes(RoomXYLightAndColorAttributes roomXYLightAndColorAttributes) {
	this->roomXYLightAndColorAttributes = roomXYLightAndColorAttributes;
}

void OGLRoomXY::draw() {
	glPushMatrix();
		glTranslated(position.getX(), position.getY(), position.getZ());
		drawFloorAndCeling();
		//drawBackWall();
		//drawLeftAndRightWalls();
	glPopMatrix();
}

void OGLRoomXY::drawFloorAndCeling() {

	glPushMatrix();
		glRotatef(270, 1, 0, 0);
		floor.draw();
	
		//glTranslated(0, 0, backWall.getHeight());
		//ceiling.draw();
	glPopMatrix();
}

void OGLRoomXY::drawBackWall() {
	
	glPushMatrix();
		glTranslated(0, 0, -floor.getHeight());
		backWall.draw();
	glPopMatrix();
}

void OGLRoomXY::drawLeftAndRightWalls() {
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		leftWall.draw();

		glTranslated(0, 0, floor.getWidth());
		rightWall.draw();
	glPopMatrix();
}
