#include "FallingObject.h"

FallingObject::FallingObject(Object3D* object3D, int scorePoints, int floorCellRow, int floorCellColumn)
	: object3D(object3D),
	scorePoints(scorePoints),
	floorCellRow(floorCellRow),
	floorCellColumn(floorCellColumn) {
}

/*FallingObject::FallingObject(const FallingObject& fallingObject)
	: object3D(fallingObject.object3D),
	scorePoints(fallingObject.scorePoints),
	floorCellRow(fallingObject.floorCellRow),
	floorCellColumn(fallingObject.floorCellColumn) {
}

FallingObject& FallingObject::operator=(const FallingObject& fallingObject) {

	if (this != &fallingObject) {
		this->object3D = fallingObject.object3D;
		this->scorePoints = fallingObject.scorePoints;
		this->floorCellRow = fallingObject.floorCellRow;
		this->floorCellColumn = fallingObject.floorCellColumn;
	}

	return *this;
}*/

FallingObject::~FallingObject() {
}

Object3D* FallingObject::getObject3D() {
	return object3D;
}

void FallingObject::setObject3D(Object3D* object3D) {
	this->object3D = object3D;
}

int FallingObject::getScorePoints() {
	return scorePoints;
}

void FallingObject::setScorePoints(int scorePoints) {
	this->scorePoints = scorePoints;
}

int FallingObject::getFloorCellRow() {
	return floorCellRow;
}

void FallingObject::setFloorCellRow(int floorCellRow) {
	this->floorCellRow = floorCellRow;
}

int FallingObject::getFloorCellColumn() {
	return floorCellColumn;
}

void FallingObject::setFloorCellColumn(int floorCellColumn) {
	this->floorCellColumn = floorCellColumn;
}
