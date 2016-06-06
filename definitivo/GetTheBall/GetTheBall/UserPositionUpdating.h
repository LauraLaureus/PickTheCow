#pragma once

#include "Game.h"

class UserPositionUpdating {
protected:
	Game& game;

	void updateUserPosition(Coordinates3D newPosition);

public:
	UserPositionUpdating(Game &game);
	UserPositionUpdating(const UserPositionUpdating& userPositionUpdating);
	UserPositionUpdating& operator=(const UserPositionUpdating& userPositionUpdating);
	~UserPositionUpdating();

	void updateUserPositionByCell(int rowIndex, int columnIndex);
	void updateUserPositionBySubCell(int subRowIndex, int subColumnIndex);
	void updateUserPositionByPoint(int x, int y);
};
