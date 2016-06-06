#include "TableXYRowVertex3DCalculation.h"

#include "TableXYSquareVertex3DCalculation.h"

std::vector<Coordinates3D*>* TableXYRowVertex3DCoordinatesCalculation::getVertex3DFromTableRow(TableXY& table, int rowIndex, int fromColumnIndex, int toColumnIndex) {
	std::vector<Coordinates3D*>* rowVertexs = new std::vector<Coordinates3D*>(2 + 2 * (toColumnIndex - fromColumnIndex + 1));

	int i = 0;
	rowVertexs->at(i++) = TableXYSquareVertex3DCoordinatesCalculation::getVertex0(table, rowIndex, fromColumnIndex);
	rowVertexs->at(i++) = TableXYSquareVertex3DCoordinatesCalculation::getVertex1(table, rowIndex, fromColumnIndex);

	for (int columnIndex = fromColumnIndex; columnIndex <= toColumnIndex; columnIndex++) {
		rowVertexs->at(i++) = TableXYSquareVertex3DCoordinatesCalculation::getVertex2(table, rowIndex, columnIndex);
		rowVertexs->at(i++) = TableXYSquareVertex3DCoordinatesCalculation::getVertex3(table, rowIndex, columnIndex);
	}

	return rowVertexs;
}
