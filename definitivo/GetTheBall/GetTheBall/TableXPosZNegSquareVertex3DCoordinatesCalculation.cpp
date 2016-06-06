#include "TableXPosZNegSquareVertex3DCoordinatesCalculation.h"

Coordinates3D* TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex0(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + columnIndex * table.getSquareWidth();
	double newZ = coordinatesV0.getY() - rowIndex * table.getSquareHeight();
	return new Coordinates3D(newX, coordinatesV0.getZ(), newZ);
}

Coordinates3D* TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex1(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + columnIndex * table.getSquareWidth();
	double newZ = coordinatesV0.getY() - (rowIndex + 1) * table.getSquareHeight();
	return new Coordinates3D(newX, coordinatesV0.getZ(), newZ);
}

Coordinates3D* TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex2(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + (columnIndex + 1) * table.getSquareWidth();
	double newZ = coordinatesV0.getY() - rowIndex * table.getSquareHeight();
	return new Coordinates3D(newX, coordinatesV0.getZ(), newZ);
}

Coordinates3D* TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex3(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + (columnIndex + 1) * table.getSquareWidth();
	double newZ = coordinatesV0.getY() - (rowIndex + 1) * table.getSquareHeight();
	return new Coordinates3D(newX, coordinatesV0.getZ(), newZ);
}
