#include "OGLTableXY.h"

#include <GLUT/GLUT.h>
#include "TableXYRowVertex3DCalculation.h"
#include "VertexLightAndColorAttributes.h"
#include "OGLVertex3D.h"

OGLTableXY::OGLTableXY(Coordinates3D position, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, bool home, TableXYLightAndColorAttributes tableXYLightAndColorAttributes)
	: TableXY(position, numberOfRows, numberOfColumns, squareHeight, squareWidth, home),
	tableXYLightAndColorAttributes(tableXYLightAndColorAttributes) {
}

OGLTableXY::~OGLTableXY() {
}

TableXYLightAndColorAttributes OGLTableXY::getTableXYLightAndColorAttributes() {
	return tableXYLightAndColorAttributes;
}

void OGLTableXY::setTableXYLightAndColorAttributes(TableXYLightAndColorAttributes tableXYLightAndColorAttributes) {
	this->tableXYLightAndColorAttributes = tableXYLightAndColorAttributes;
}

void OGLTableXY::draw() {
	glPushMatrix();
		glTranslated(position.getX(), position.getY(), position.getZ());

		for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {

			std::vector<Coordinates3D*>* rowVertexsCoordinates = TableXYRowVertex3DCoordinatesCalculation::getVertex3DFromTableRow(*this, rowIndex, 0, numberOfColumns - 1);

			int vertexIndex = 0;
			for (int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++) {

				RGBColor color = getCellColor(rowIndex, columnIndex);
				Coordinates3D c0 = *(rowVertexsCoordinates->at(vertexIndex));
				Coordinates3D c1 = *(rowVertexsCoordinates->at(vertexIndex + 1));
				Coordinates3D c2 = *(rowVertexsCoordinates->at(vertexIndex + 2));
				Coordinates3D c3 = *(rowVertexsCoordinates->at(vertexIndex + 3));
				drawTableCell(c0, c1, c2, c3, color, tableXYLightAndColorAttributes);

				vertexIndex += 2;
			}

			deleteRowVertex(rowVertexsCoordinates);
		}
	glPopMatrix();
}

void OGLTableXY::deleteRowVertex(std::vector<Coordinates3D*>* rowVertexsCoordinates) {
	int numberOfVertex = rowVertexsCoordinates->capacity();
	for (int vertexIndex = 0; vertexIndex < numberOfVertex; vertexIndex++) {
		delete rowVertexsCoordinates->at(vertexIndex);
	}
	delete rowVertexsCoordinates;
}

RGBColor OGLTableXY::getCellColor(int rowIndex, int columnIndex) {
	if ((home) && (rowIndex == 0)) {
		return tableXYLightAndColorAttributes.getHomeColor();
	}
	else {
		if (rowIndex % 2 == 0) {
			return (columnIndex % 2 == 0) ? tableXYLightAndColorAttributes.getCellColor1() : tableXYLightAndColorAttributes.getCellColor2();
		}
		else {
			return (columnIndex % 2 == 0) ? tableXYLightAndColorAttributes.getCellColor2() : tableXYLightAndColorAttributes.getCellColor1();
		}
	}
}

void OGLTableXY::drawTableCell(Coordinates3D c0, Coordinates3D c1, Coordinates3D c2, Coordinates3D c3, RGBColor color, TableXYLightAndColorAttributes tableXYLightAndColorAttributes) {
	tableXYLightAndColorAttributes.applyAttributes(color);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3d(c0.getX(), c0.getY(), c0.getZ());
		glVertex3d(c1.getX(), c1.getY(), c1.getZ());
		glVertex3d(c2.getX(), c2.getY(), c2.getZ());
		glVertex3d(c3.getX(), c3.getY(), c3.getZ());

		// Lo siguiente interpola el color y no produce el efecto damero deseado
		/*(OGLVertex3D(c0, VertexLightAndColorAttributes(color))).draw();
		(OGLVertex3D(c1, VertexLightAndColorAttributes(color))).draw();
		(OGLVertex3D(c2, VertexLightAndColorAttributes(color))).draw();
		(OGLVertex3D(c3, VertexLightAndColorAttributes(color))).draw();*/
	glEnd();
}
