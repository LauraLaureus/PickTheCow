#include "RoomXY.h"

RoomXY::RoomXY(Coordinates3D position, TableXY& floor, TableXY& ceiling, TableXY& leftWall, TableXY& rightWall, TableXY& backWall)
	: Object3D(position),
	floor(floor),
	ceiling(ceiling),
	leftWall(leftWall),
	rightWall(rightWall),
	backWall(backWall) {
}

RoomXY::RoomXY(const RoomXY& roomXY)
	: Object3D(roomXY.position),
	floor(roomXY.floor),
	ceiling(roomXY.ceiling),
	leftWall(roomXY.leftWall),
	rightWall(roomXY.rightWall),
	backWall(roomXY.backWall) {
}
RoomXY& RoomXY::operator=(const RoomXY& roomXY) {
	
	if (this != &roomXY) {
		this->position = roomXY.position;
		this->floor = roomXY.floor;
		this->ceiling = roomXY.ceiling;
		this->leftWall = roomXY.leftWall;
		this->rightWall = roomXY.rightWall;
		this->backWall = roomXY.backWall;
	}
	
	return *this;
}

RoomXY::~RoomXY() {
}

TableXY& RoomXY::getFloor() {
	return floor;
}

void RoomXY::setFloor(TableXY& Floor) {
	this->floor = floor;
}

TableXY& RoomXY::getCeiling() {
	return ceiling;
}

void RoomXY::setCeiling(TableXY& Ceiling) {
	this->ceiling = ceiling;
}

TableXY& RoomXY::getLeftWall() {
	return leftWall;
}

void RoomXY::setLeftWall(TableXY& LeftWall) {
	this->leftWall = leftWall;
}

TableXY& RoomXY::getRightWall() {
	return rightWall;
}

void RoomXY::setRightWall(TableXY& RightWall) {
	this->rightWall = rightWall;
}

TableXY& RoomXY::getBackWall() {
	return backWall;
}

void RoomXY::setBackWall(TableXY& BackWall) {
	this->backWall = backWall;
}

double RoomXY::getHeight() {
	return backWall.getHeight();
}

double RoomXY::getWidth() {
	return floor.getWidth();
}

double RoomXY::getDepth() {
	return floor.getHeight();
}