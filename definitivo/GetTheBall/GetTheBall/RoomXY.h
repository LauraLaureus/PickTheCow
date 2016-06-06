#pragma once

#include "Object3D.h"
#include "Coordinates3D.h"
#include "TableXY.h"

class RoomXY : public Object3D {
protected:
	TableXY& floor;
	TableXY& ceiling;
	TableXY& leftWall;
	TableXY& rightWall;
	TableXY& backWall;

public:
	RoomXY(Coordinates3D position, TableXY& floor, TableXY& ceiling, TableXY& leftWall, TableXY& rightWall, TableXY& backWall);
	RoomXY(const RoomXY& roomXY);
	RoomXY& operator=(const RoomXY& roomXY);
	~RoomXY();

	TableXY& getFloor();
	void setFloor(TableXY& Floor);

	TableXY& getCeiling();
	void setCeiling(TableXY& Ceiling);

	TableXY& getLeftWall();
	void setLeftWall(TableXY& LeftWall);

	TableXY& getRightWall();
	void setRightWall(TableXY& RightWall);

	TableXY& getBackWall();
	void setBackWall(TableXY& BackWall);

	double getHeight();
	double getWidth();
	double getDepth();
};
