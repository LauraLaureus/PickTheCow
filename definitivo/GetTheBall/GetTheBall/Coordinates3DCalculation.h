#pragma once

#include "GameArea.h"
#include "Coordinates3D.h"

class Coordinates3DCalculation {
private:
	int rowIndex;
	int columnIndex;
	GameArea gameArea;
	double positionY;

public:
	Coordinates3DCalculation(int rowIndex, int columnIndex, GameArea gameArea, double positionY);
	~Coordinates3DCalculation();

	static Coordinates3D getVertex0(int rowIndex, int columnIndex, GameArea gameArea, double positionY);
	static Coordinates3D getVertex1(int rowIndex, int columnIndex, GameArea gameArea, double positionY);
	static Coordinates3D getVertex2(int rowIndex, int columnIndex, GameArea gameArea, double positionY);
	static Coordinates3D getVertex3(int rowIndex, int columnIndex, GameArea gameArea, double positionY);

	static Coordinates3D getSubVertex0(int rowIndex, int columnIndex, GameArea gameArea, double positionY);
	static Coordinates3D getSubVertex1(int rowIndex, int columnIndex, GameArea gameArea, double positionY);
	static Coordinates3D getSubVertex2(int rowIndex, int columnIndex, GameArea gameArea, double positionY);
	static Coordinates3D getSubVertex3(int rowIndex, int columnIndex, GameArea gameArea, double positionY);

	Coordinates3D executeByCells();
	Coordinates3D executeBySubCells();
};
