#include "NewFallingObjectCreation.h"

NewFallingObjectCreation::NewFallingObjectCreation(Game& game)
	: game(game) {
}

NewFallingObjectCreation::NewFallingObjectCreation(const NewFallingObjectCreation& newFallingObjectCreation) 
	: game(newFallingObjectCreation.game) {
}

NewFallingObjectCreation::~NewFallingObjectCreation() {
}

NewFallingObjectCreation& NewFallingObjectCreation::operator=(const NewFallingObjectCreation& newFallingObjectCreation) {
	if (this != &newFallingObjectCreation) {
		this->game = newFallingObjectCreation.game;
	}

	return *this;
}

void NewFallingObjectCreation::execute(FallingObject* newFallingObject) {
	if (isUserInPlayingMode()) {
		Scene scene = game.getScene();
		std::list<FallingObject*> fallingObjects = scene.getFallingObjects();
		if (fallingObjects.size() < game.getFallingObjectsProperties().getMaximunQuantity()) {
			fallingObjects.push_back(newFallingObject);
			scene.setFallingObjects(fallingObjects);
			game.setScene(scene);
		}
	}
}

bool NewFallingObjectCreation::isUserInPlayingMode() {
	return game.getGameMode() == Game::GAMEMODE_PLAYING;
}
