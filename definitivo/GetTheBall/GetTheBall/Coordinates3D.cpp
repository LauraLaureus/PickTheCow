#include "Coordinates3D.h"

Coordinates3D::Coordinates3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Coordinates3D::~Coordinates3D() {
}

double Coordinates3D::getX() {
	return x;
}

void Coordinates3D::setX(double x) {
	this->x = x;
}

double Coordinates3D::getY() {
	return y;
}

void Coordinates3D::setY(double y) {
	this->y = y;
}

double Coordinates3D::getZ() {
	return z;
}

void Coordinates3D::setZ(double z) {
	this->z = z;
}

bool Coordinates3D::equals(Coordinates3D coordinates3D) {
	return x == coordinates3D.getX() && y == coordinates3D.getY() && z == coordinates3D.getX();
}
