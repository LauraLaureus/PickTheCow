#include "Object3D.h"

Object3D::Object3D(Coordinates3D position) 
	: position(position) {
}

Object3D::~Object3D() {
}

Coordinates3D Object3D::getPosition() {
	return position;
}

void Object3D::setPosition(Coordinates3D position) {
	this->position = position;
}