#pragma once

#include "Object3D.h"
#include "Coordinates3D.h"

class TableXY : public Object3D {
protected:
	int numberOfRows;
	int numberOfColumns;
	double squareHeight;
	double squareWidth;
	bool home;

public:
	TableXY(Coordinates3D position, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, bool home);
	~TableXY();

	int getNumberOfRows();
	void setNumberOfRows(int numberOfRows);

	int getNumberOfColumns();
	void setNumberOfColumns(int numberOfColumns);

	double getSquareHeight();
	void setSquareHeight(int squareHeight);

	double getSquareWidth();
	void setSquareWidth(double squareWidth);

	bool hasHome();
	void setHome(bool home);

	double getHeight();
	double getWidth();
};
