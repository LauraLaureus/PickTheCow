#include "FallingObjectsHandling.h"

#include "EuclideanDistance.h"

FallingObjectsHandling::FallingObjectsHandling(Game& game)
	: game(game) {
}

FallingObjectsHandling::FallingObjectsHandling(const FallingObjectsHandling& fallingObjectsHandling) 
	: game(fallingObjectsHandling.game) {
}

FallingObjectsHandling& FallingObjectsHandling::operator=(const FallingObjectsHandling& fallingObjectsHandling) {

	if (this != &fallingObjectsHandling) {
		this->game = fallingObjectsHandling.game;
	}

	return *this;
}

FallingObjectsHandling::~FallingObjectsHandling() {
}

void FallingObjectsHandling::execute() {
	if (isUserInPlayingMode()) {
		double minimunDistanceToFloor = game.getFallingObjectsProperties().getMinimunDistanceToFloor();
		
		Scene scene = game.getScene();
		Score& score = scene.getScore();
		std::list<FallingObject*> fallingObjects = scene.getFallingObjects();

		std::list<FallingObject*>::iterator fallingObject = fallingObjects.begin();
		while (fallingObject != fallingObjects.end()) {
			bool userIsNearFallingObject = isUserNearFallingObject(*fallingObject);
			if (userIsNearFallingObject || isFallingObjectNearTheFloor(*fallingObject, minimunDistanceToFloor)) {

				if (userIsNearFallingObject) {
					score.increment((*fallingObject)->getScorePoints());
					scene.setScore(score);
				}

				FallingObject* fo = *fallingObject;
				fallingObject = fallingObjects.erase(fallingObject);
				delete fo;
			}
			else {
				++fallingObject;
			}
		}
		
		scene.setFallingObjects(fallingObjects);
		game.setScene(scene);
	}
}

bool FallingObjectsHandling::isUserInPlayingMode() {
	return game.getGameMode() == Game::GAMEMODE_PLAYING;
}

bool FallingObjectsHandling::isUserNearFallingObject(FallingObject *fallingObject) {

	Coordinates3D userPosition = game.getScene().getUser().getObject3D().getPosition();
	Coordinates3D fallingObjectPosition = fallingObject->getObject3D()->getPosition();
	double distance = EuclideanDistance::solve(userPosition, fallingObjectPosition);

	return (distance <= game.getScene().getUser().getMaxCatchDistance());
}

bool FallingObjectsHandling::isFallingObjectNearTheFloor(FallingObject* fallingObject, double minimunDistanceToFloor) {
	double fallingObjectY = fallingObject->getObject3D()->getPosition().getY();
	return fallingObjectY < minimunDistanceToFloor;
}
