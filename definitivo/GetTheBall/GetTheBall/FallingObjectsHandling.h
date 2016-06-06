#pragma once

#include "Game.h"

class FallingObjectsHandling {
protected:
	Game& game;

	bool isUserInPlayingMode();
	bool isUserNearFallingObject(FallingObject *fallingObject);
	bool isFallingObjectNearTheFloor(FallingObject* fallingObject, double minimunDistanceToFloor);
	
public:
	FallingObjectsHandling(Game& game);
	FallingObjectsHandling(const FallingObjectsHandling& fallingObjectsHandling);
	FallingObjectsHandling& operator=(const FallingObjectsHandling& fallingObjectsHandling);

	~FallingObjectsHandling();

	void execute();
};
