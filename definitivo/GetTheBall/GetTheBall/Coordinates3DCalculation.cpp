#include "Coordinates3DCalculation.h"

Coordinates3DCalculation::Coordinates3DCalculation(int rowIndex, int columnIndex, GameArea gameArea, double positionY)
	: rowIndex(rowIndex), columnIndex(columnIndex), gameArea(gameArea), positionY(positionY) {
}

Coordinates3DCalculation::~Coordinates3DCalculation() {
}

Coordinates3D Coordinates3DCalculation::getVertex0(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = columnIndex * gameArea.getTableCellWidth();
	double newZ = -rowIndex * gameArea.getTableCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::getVertex1(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = columnIndex * gameArea.getTableCellWidth();
	double newZ = -(rowIndex + 1) * gameArea.getTableCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::getVertex2(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = (columnIndex + 1) * gameArea.getTableCellWidth();
	double newZ = -rowIndex * gameArea.getTableCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::getVertex3(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = (columnIndex + 1) * gameArea.getTableCellWidth();
	double newZ = -(rowIndex + 1) * gameArea.getTableCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::getSubVertex0(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = columnIndex * gameArea.getTableSubCellWidth();
	double newZ = -rowIndex * gameArea.getTableSubCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::getSubVertex1(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = columnIndex * gameArea.getTableSubCellWidth();
	double newZ = -(rowIndex + 1) * gameArea.getTableSubCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::getSubVertex2(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = (columnIndex + 1) * gameArea.getTableSubCellWidth();
	double newZ = -rowIndex * gameArea.getTableSubCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::getSubVertex3(int rowIndex, int columnIndex, GameArea gameArea, double positionY) {
	double newX = (columnIndex + 1) * gameArea.getTableSubCellWidth();
	double newZ = -(rowIndex + 1) * gameArea.getTableSubCellHeight();
	return Coordinates3D(newX, positionY, newZ);
}

Coordinates3D Coordinates3DCalculation::executeByCells() {
	Coordinates3D v0 = getVertex0(rowIndex, columnIndex, gameArea, positionY);
	Coordinates3D v3 = getVertex3(rowIndex, columnIndex, gameArea, positionY);

	double newX = (v3.getX() + v0.getX()) / (double)2;
	double newY = (v3.getY() + v0.getY()) / (double)2;
	double newZ = (v3.getZ() + v0.getZ()) / (double)2;

	return Coordinates3D(newX, newY, newZ);
}

Coordinates3D Coordinates3DCalculation::executeBySubCells() {
	Coordinates3D v0 = getSubVertex0(rowIndex, columnIndex, gameArea, positionY);
	Coordinates3D v3 = getSubVertex3(rowIndex, columnIndex, gameArea, positionY);

	double newX = (v3.getX() + v0.getX()) / (double)2;
	double newY = (v3.getY() + v0.getY()) / (double)2;
	double newZ = (v3.getZ() + v0.getZ()) / (double)2;

	return Coordinates3D(newX, newY, newZ);
}
