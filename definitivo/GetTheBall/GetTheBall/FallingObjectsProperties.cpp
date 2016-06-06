#include "FallingObjectsProperties.h"

FallingObjectsProperties::FallingObjectsProperties(int maximunQuantity, int creationPeriod, int updatingPeriod, double fallingDistanceIncrement, double minimunDistanceToFloor)
	: maximunQuantity(maximunQuantity),
	creationPeriod(creationPeriod),
	updatingPeriod(updatingPeriod),
	fallingDistanceIncrement(fallingDistanceIncrement),
	minimunDistanceToFloor(minimunDistanceToFloor) {
}

FallingObjectsProperties::~FallingObjectsProperties() {
}

unsigned int FallingObjectsProperties::getMaximunQuantity() {
	return maximunQuantity;
}

void FallingObjectsProperties::setMaximunQuantity(unsigned int maximunQuantity) {
	this->maximunQuantity = maximunQuantity;
}

int FallingObjectsProperties::getCreationPeriod() {
	return creationPeriod;
}

void FallingObjectsProperties::setCreationPeriod(int creationPeriod) {
	this->creationPeriod = creationPeriod;
}

int FallingObjectsProperties::getUpdatingPeriod() {
	return updatingPeriod;
}

void FallingObjectsProperties::setUpdatingPeriod(int updatingPeriod) {
	this->updatingPeriod = updatingPeriod;
}

double FallingObjectsProperties::getFallingDistanceIncrement() {
	return fallingDistanceIncrement;
}

void FallingObjectsProperties::setFallingDistanceIncrement(double fallingDistanceIncrement) {
	this->fallingDistanceIncrement = fallingDistanceIncrement;
}

double FallingObjectsProperties::getMinimunDistanceToFloor() {
	return minimunDistanceToFloor;
}

void FallingObjectsProperties::setMinimunDistanceToFloor(double distanceToFinalPosition) {
	this->minimunDistanceToFloor = minimunDistanceToFloor;
}
