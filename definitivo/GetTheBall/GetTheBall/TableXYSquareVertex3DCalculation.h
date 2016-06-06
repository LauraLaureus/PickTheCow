#pragma once

#include "TableXY.h"

class TableXYSquareVertex3DCoordinatesCalculation {

public:
	static Coordinates3D* getVertex0(TableXY& table, int rowIndex, int columnIndex);
	static Coordinates3D* getVertex1(TableXY& table, int rowIndex, int columnIndex);
	static Coordinates3D* getVertex2(TableXY& table, int rowIndex, int columnIndex);
	static Coordinates3D* getVertex3(TableXY& table, int rowIndex, int columnIndex);
};
