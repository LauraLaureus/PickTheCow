#include "Game.h"

Game::Game(Scene scene, int inititalGameMode, FallingObjectsProperties fallingObjectsProperties, GameArea& gameArea)
	: scene(scene),
	gameMode(inititalGameMode),
	fallingObjectsProperties(fallingObjectsProperties),
	gameArea(gameArea) {
}

Game::Game(const Game& game)
	: scene(game.scene),
	gameMode(game.gameMode),
	fallingObjectsProperties(game.fallingObjectsProperties),
	gameArea(game.gameArea) {
}

Game& Game::operator=(const Game& game) {

	if (this != &game) {
		this->scene = game.scene;
		this->gameMode= game.gameMode;
		this->fallingObjectsProperties = game.fallingObjectsProperties;
		this->gameArea = game.gameArea;
	}

	return *this;
}

Game::~Game() {
}

Scene Game::getScene() {
	return scene;
}

void Game::setScene(Scene scene) {
	this->scene = scene;
}

int Game::getGameMode() {
	return gameMode;
}

void Game::setGameMode(int gameMode) {
	this->gameMode = gameMode;
}

FallingObjectsProperties Game::getFallingObjectsProperties() {
	return fallingObjectsProperties;
}

void Game::setFallingObjectsProperties(FallingObjectsProperties fallingObjectsProperties) {
	this->fallingObjectsProperties = fallingObjectsProperties;
}

GameArea& Game::getGameArea() {
	return gameArea;
}

void Game::setGameArea(GameArea& gameArea) {
	this->gameArea = gameArea;
}
