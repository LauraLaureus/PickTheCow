#pragma once

#include "Coordinates3D.h"
#include "TableXY.h"

class Conversion {

public:
	static int getRowIndexFromSubRowIndex(int subRowIndex, int numberOfSubRows);
	static int getColumnIndexFromSubColumnIndex(int subColumnIndex, int numberOfSubColumns);

	static Coordinates3D getCoordinates3DFromRowAndColumnIndexes(TableXY& table, int rowIndex, int columnIndex);
};
