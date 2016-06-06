#pragma once

#include "Object3D.h"

class FallingObject {
protected:
	Object3D* object3D;
	int scorePoints;
	int floorCellRow;
	int floorCellColumn;	

public:
	FallingObject(Object3D* object3D, int scorePoints, int floorCellRow, int floorCellColumn);
    //FallingObject(const FallingObject& fallingObject);
    //FallingObject& operator=(const FallingObject& fallingObject);
	~FallingObject();
	
	Object3D* getObject3D();
	void setObject3D(Object3D* object3D);

	int getScorePoints();
	void setScorePoints(int scorePoints);

	int getFloorCellRow();
	void setFloorCellRow(int floorCellRow);

	int getFloorCellColumn();
	void setFloorCellColumn(int floorCellColumn);
};
