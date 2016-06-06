#pragma once

#include "TableXY.h"
#include "Vertex3D.h"

#include <vector>

class TableXYRowVertex3DCoordinatesCalculation {

public:
	static std::vector<Coordinates3D*>* getVertex3DFromTableRow(TableXY& table, int rowIndex, int fromColumnIndex, int toColumnIndex);
};
