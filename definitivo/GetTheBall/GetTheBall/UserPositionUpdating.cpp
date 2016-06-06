#include "UserPositionUpdating.h"

#include "Conversion.h"
#include "Coordinates3DCalculation.h"

UserPositionUpdating::UserPositionUpdating(Game& game)
	: game(game) {
}

UserPositionUpdating::UserPositionUpdating(const UserPositionUpdating& userPositionUpdating) 
	: game(userPositionUpdating.game) {
}

UserPositionUpdating& UserPositionUpdating::operator=(const UserPositionUpdating& userPositionUpdating) {
	if (this != &userPositionUpdating) {
		this->game = userPositionUpdating.game;
	}

	return *this;
}

UserPositionUpdating::~UserPositionUpdating() {
}

void UserPositionUpdating::updateUserPositionByCell(int rowIndex, int columnIndex) {
	Coordinates3D roomPosition = game.getScene().getRoomXY().getPosition();
	Coordinates3D relativePosition = Coordinates3DCalculation(rowIndex, columnIndex, game.getGameArea(), roomPosition.getY()).executeByCells();
	updateUserPosition(
		Coordinates3D(
			roomPosition.getX() + relativePosition.getX(),
			roomPosition.getY() + relativePosition.getY(),
			roomPosition.getZ() + relativePosition.getZ()));
}

void UserPositionUpdating::updateUserPositionBySubCell(int subRowIndex, int subColumnIndex) {
	Coordinates3D roomPosition = game.getScene().getRoomXY().getPosition();
	Coordinates3D relativePosition = Coordinates3DCalculation(subRowIndex, subColumnIndex, game.getGameArea(), roomPosition.getY()).executeBySubCells();
	updateUserPosition(
		Coordinates3D(
		roomPosition.getX() + relativePosition.getX(),
		roomPosition.getY() + relativePosition.getY(),
		roomPosition.getZ() + relativePosition.getZ()));
}

void UserPositionUpdating::updateUserPositionByPoint(int x, int y) {
	GameArea gameArea = game.getGameArea();
	int subRowIndex = gameArea.getSubRowIndexFromRealWorld(y);
	int subColumnIndex = gameArea.getSubColumnIndexFromRealWorld(x);

	updateUserPositionBySubCell(subRowIndex, subColumnIndex);
}

void UserPositionUpdating::updateUserPosition(Coordinates3D newPosition) {
	Scene scene = game.getScene();
	User user = scene.getUser();
	Object3D& userObject = user.getObject3D();
	userObject.setPosition(newPosition);
	user.setObject3D(userObject);
	scene.setUser(user);
	game.setScene(scene);
}
