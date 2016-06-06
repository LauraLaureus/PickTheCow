#include "Conversion.h"

#include "Vertex3D.h"
#include "TableXPosZNegSquareVertex3DCoordinatesCalculation.h"

int Conversion::getRowIndexFromSubRowIndex(int subRowIndex, int numberOfSubRows) {
	return subRowIndex / numberOfSubRows;
}

int Conversion::getColumnIndexFromSubColumnIndex(int subColumnIndex, int numberOfSubColumns) {
	return subColumnIndex / numberOfSubColumns;
}

Coordinates3D Conversion::getCoordinates3DFromRowAndColumnIndexes(TableXY& table, int rowIndex, int columnIndex) {
	Coordinates3D* v0 = TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex0(table, rowIndex, columnIndex);
	Coordinates3D* v3 = TableXPosZNegSquareVertex3DCoordinatesCalculation::getVertex3(table, rowIndex, columnIndex);

	double newX = (v3->getX() + v0->getX()) / (double)2;
	double newY = (v3->getY() + v0->getY()) / (double)2;
	double newZ = (v3->getZ() + v0->getZ()) / (double)2;
	
	delete v0;
	delete v3;

	return Coordinates3D(newX, newY, newZ);
}
