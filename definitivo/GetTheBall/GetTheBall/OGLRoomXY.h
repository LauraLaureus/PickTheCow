#pragma once

#include "RoomXY.h"

#include "RoomXYLightAndColorAttributes.h"

class OGLRoomXY : public RoomXY {
protected:
	RoomXYLightAndColorAttributes roomXYLightAndColorAttributes;

	void drawFloorAndCeling();
	void drawBackWall();
	void drawLeftAndRightWalls();

public:
	OGLRoomXY(Coordinates3D position, TableXY& floor, TableXY& ceiling, TableXY& leftWall, TableXY& rightWall, TableXY& backWall, RoomXYLightAndColorAttributes roomXYLightAndColorAttributes);
	~OGLRoomXY();

	RoomXYLightAndColorAttributes getRoomXYLightAndColorAttributes();
	void setRoomXYLightAndColorAttributes(RoomXYLightAndColorAttributes roomXYLightAndColorAttributes);

	virtual void draw();
};
