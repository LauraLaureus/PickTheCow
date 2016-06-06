#pragma once

#include "Game.h"

class NewFallingObjectCreation {
protected:
	Game& game;

	bool isUserInPlayingMode();

public:
	NewFallingObjectCreation(Game& game);
	NewFallingObjectCreation(const NewFallingObjectCreation& newFallingObjectCreation);
	NewFallingObjectCreation& operator=(const NewFallingObjectCreation& newFallingObjectCreation);
	~NewFallingObjectCreation();

	void execute(FallingObject* newFallingObject);
};

