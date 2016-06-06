#pragma once

#include "Game.h"
#include "RGBColor.h"

#include "OGLTableXY.h"
#include "OGLRoomXY.h"
#include "OGLModeledObject.h"
#include "OGLScore.h"

#include "Model_PLY.h"

#include "FallingObjectsHandling.h"
#include "FallingObjectsPositionUpdating.h"
#include "NewFallingObjectCreation.h"
#include "UserPositionUpdating.h"
#include "GameArea.h"

class TestGame {
private:
	#define numberOfFallingObjects 3
	#define numberOfColors 4

protected:
	Game* game;


	OGLTableXY* floor;
	OGLTableXY* ceiling;
	OGLTableXY* back;
	OGLTableXY* left;
	OGLTableXY* right;
	OGLRoomXY* roomXY;
	Model_PLY* model_PLY;
	OGLModeledObject* userModeledObject;
	User* user;
	OGLScore* score;
	Scene* scene;
	FallingObjectsProperties* fallingObjectsProperties;
	GameArea* gameArea;

	FallingObjectsHandling* fallingObjectsHandling;
	FallingObjectsPositionUpdating* fallingObjectsPositionUpdating;
	NewFallingObjectCreation* newFallingObjectCreation;
	UserPositionUpdating* userPositionUpdating;

	FallingObject* getNewFallingObject();
	void highligthTableCell(Coordinates3D position);
	
public:
	TestGame(double left, double right, double bottom, double top, int numberOfRows, int numberOfColumns, int numberOfSubRows, int numberOfSubColumns, double tableCellHeight, double tableCellWidth,
		double positionX, double positionY, double positionZ,
		RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor,
		unsigned int maximunQuantity, int creationPeriod, int positionUpdatingPeriod, double fallingDistanceIncrement, double minimunDistanceToFloor,
		double maxCatchDistance, int userLaserRow, int userLaserColumn, char* userFileName, RGBColor userColor, double userScaleFactor,
		double scoreX, double scoreY, double scoreZ, RGBColor scoreColor, void* font);
	~TestGame();

	Game* getGame();

	void init();
	void display();

	void handleFallingObjects();
	void updateFallingObjectsPosition();
	void createNewFallingObject();
	
	void updateUserPositionByCell(int rowIndex, int columnIndex);
	void updateUserPositionBySubCell(int subRowIndex, int subColumnIndex);
	void updateUserPositionByPoint(int x, int y);
};

