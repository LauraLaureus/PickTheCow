#include "FallingObjectsPositionUpdating.h"

FallingObjectsPositionUpdating::FallingObjectsPositionUpdating(Game& game)
	: game(game) {
}

FallingObjectsPositionUpdating::FallingObjectsPositionUpdating(const FallingObjectsPositionUpdating& fallingObjectsPositionUpdating) 
	: game(fallingObjectsPositionUpdating.game) {

}

FallingObjectsPositionUpdating& FallingObjectsPositionUpdating::operator=(const FallingObjectsPositionUpdating& fallingObjectsPositionUpdating) {
	if (this != &fallingObjectsPositionUpdating) {
		this->game = fallingObjectsPositionUpdating.game;
	}

	return *this;
}

FallingObjectsPositionUpdating::~FallingObjectsPositionUpdating() {
}

void FallingObjectsPositionUpdating::execute() {
	if (isUserInPlayingMode()) {
		Scene scene = game.getScene();
		std::list<FallingObject*> fallingObjects = scene.getFallingObjects();
		for (std::list<FallingObject*>::iterator fallingObject = fallingObjects.begin(); fallingObject != fallingObjects.end(); ++fallingObject) {
			Object3D* object3D = (*fallingObject)->getObject3D();
			Coordinates3D position = object3D->getPosition();
			position.setY(position.getY() - game.getFallingObjectsProperties().getFallingDistanceIncrement());
			object3D->setPosition(position);
			(*fallingObject)->setObject3D(object3D);
		}
		scene.setFallingObjects(fallingObjects);
		game.setScene(scene);
	}
}

bool FallingObjectsPositionUpdating::isUserInPlayingMode() {
	return game.getGameMode() == Game::GAMEMODE_PLAYING;
}