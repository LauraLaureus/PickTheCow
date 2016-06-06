#pragma once

#include "RGBColor.h"

class Test {
public:
	Test();
	~Test();

	void drawTableXY(double positionX, double positionY, double positionZ, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor, bool home);
	void drawRoomXY(double positionX, double positionY, double positionZ, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor);
	void drawModeledObject(double positionX, double positionY, double positionZ, char* fileName, RGBColor color, double scaleFactor);
	void drawScore(double positionX, double positionY, double positionZ, int score, void* font, RGBColor color);
};
