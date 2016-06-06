#include "Test.h"

#include "OGLTableXY.h"
#include "OGLRoomXY.h"
#include "OGLModeledObject.h"
#include "OGLScore.h"

#include "Model_PLY.h"


Test::Test() {
}

Test::~Test() {
}

void Test::drawTableXY(double positionX, double positionY, double positionZ, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor, bool home) {

	Coordinates3D position = Coordinates3D(positionX, positionY, positionZ);	
	TableXYLightAndColorAttributes tableXYLightAndColorAttributes = TableXYLightAndColorAttributes(cellColor1, cellColor2, homeColor);
	OGLTableXY tableXY = OGLTableXY(position, numberOfRows, numberOfColumns, squareHeight, squareWidth, home, tableXYLightAndColorAttributes);
	tableXY.draw();
}


void Test::drawRoomXY(double positionX, double positionY, double positionZ, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor) {

	Coordinates3D position = Coordinates3D(positionX, positionY, positionZ);
	bool home = true;
	
	TableXYLightAndColorAttributes tableXYLightAndColorAttributes = TableXYLightAndColorAttributes(cellColor1, cellColor2, homeColor);
	OGLTableXY floor = OGLTableXY(position, numberOfRows, numberOfColumns, squareHeight, squareWidth, home, tableXYLightAndColorAttributes);
	OGLTableXY ceiling = OGLTableXY(position, numberOfRows, numberOfColumns, squareHeight, squareWidth, !home, tableXYLightAndColorAttributes);
	OGLTableXY back = OGLTableXY(position, numberOfRows, numberOfColumns, squareHeight, squareWidth, !home, tableXYLightAndColorAttributes);
	OGLTableXY left = OGLTableXY(position, numberOfRows, numberOfColumns, squareHeight, squareWidth, !home, tableXYLightAndColorAttributes);
	OGLTableXY right = OGLTableXY(position, numberOfRows, numberOfColumns, squareHeight, squareWidth, !home, tableXYLightAndColorAttributes);
	RoomXYLightAndColorAttributes roomXYLightAndColorAttributes = RoomXYLightAndColorAttributes();
	OGLRoomXY roomXY = OGLRoomXY(position, floor, ceiling, back, left, right, roomXYLightAndColorAttributes);
	roomXY.draw();
}

void Test::drawModeledObject(double positionX, double positionY, double positionZ, char* fileName, RGBColor color, double scaleFactor) {
	
	Coordinates3D position = Coordinates3D(positionX, positionY, positionZ);
	Model_PLY *model_PLY = new Model_PLY();
	model_PLY->Load(fileName);
	ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes = ModeledObjectLightAndColorAttributes(color);
	OGLModeledObject modeledObject = OGLModeledObject(position, model_PLY, modeledObjectLightAndColorAttributes, scaleFactor);
	modeledObject.draw();
	delete model_PLY;
}

void Test::drawScore(double positionX, double positionY, double positionZ, int score, void* font, RGBColor color) {

	Coordinates3D position = Coordinates3D(positionX, positionY, positionZ);
	ScoreLightAndColorAttributes scoreLightAndColorAttributes = ScoreLightAndColorAttributes(color);
	OGLScore scoreObject = OGLScore(position, score, font, scoreLightAndColorAttributes);
	scoreObject.draw();
	
}
