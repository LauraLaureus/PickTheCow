#pragma once

#include <vector>

#include "TableXY.h"
#include "TableXYLightAndColorAttributes.h"
#include "RGBColor.h"

class OGLTableXY : public TableXY {
protected:
	TableXYLightAndColorAttributes tableXYLightAndColorAttributes;

	void deleteRowVertex(std::vector<Coordinates3D*>* rowVertexsCoordinates);
	RGBColor getCellColor(int rowIndex, int columnIndex);
	
public:
	OGLTableXY(Coordinates3D position, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, bool home, TableXYLightAndColorAttributes tableXYLightAndColorAttributes);
	~OGLTableXY();

	TableXYLightAndColorAttributes getTableXYLightAndColorAttributes();
	void setTableXYLightAndColorAttributes(TableXYLightAndColorAttributes tableXYLightAndColorAttributes);

	static void drawTableCell(Coordinates3D c0, Coordinates3D c1, Coordinates3D c2, Coordinates3D c3, RGBColor color, TableXYLightAndColorAttributes tableXYLightAndColorAttributes);

	virtual void draw();
};

