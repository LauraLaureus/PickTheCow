#include "TableXYSquareVertex3DCalculation.h"

Coordinates3D* TableXYSquareVertex3DCoordinatesCalculation::getVertex0(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + columnIndex * table.getSquareWidth();
	double newY = coordinatesV0.getY() + rowIndex * table.getSquareHeight();
	return new Coordinates3D(newX, newY, coordinatesV0.getZ());
}

Coordinates3D* TableXYSquareVertex3DCoordinatesCalculation::getVertex1(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + columnIndex * table.getSquareWidth();
	double newY = coordinatesV0.getY() + (rowIndex + 1) * table.getSquareHeight();
	return new Coordinates3D(newX, newY, coordinatesV0.getZ());
}

Coordinates3D* TableXYSquareVertex3DCoordinatesCalculation::getVertex2(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + (columnIndex + 1) * table.getSquareWidth();
	double newY = coordinatesV0.getY() + rowIndex * table.getSquareHeight();
	return new Coordinates3D(newX, newY, coordinatesV0.getZ());
}

Coordinates3D* TableXYSquareVertex3DCoordinatesCalculation::getVertex3(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D coordinatesV0 = table.getPosition();
	double newX = coordinatesV0.getX() + (columnIndex + 1) * table.getSquareWidth();
	double newY = coordinatesV0.getY() + (rowIndex + 1) * table.getSquareHeight();
	return new Coordinates3D(newX, newY, coordinatesV0.getZ());
}
