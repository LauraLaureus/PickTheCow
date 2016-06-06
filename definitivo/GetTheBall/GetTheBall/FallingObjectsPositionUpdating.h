#pragma once

#include "Game.h"

class FallingObjectsPositionUpdating {
protected:
	Game& game;

	bool isUserInPlayingMode();

public:
	FallingObjectsPositionUpdating(Game& game);
	FallingObjectsPositionUpdating(const FallingObjectsPositionUpdating& fallingObjectsPositionUpdating);
	FallingObjectsPositionUpdating& operator=(const FallingObjectsPositionUpdating& fallingObjectsPositionUpdating);

	~FallingObjectsPositionUpdating();

	void execute();
};
