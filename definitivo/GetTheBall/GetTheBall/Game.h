#pragma once

#include "Scene.h"
#include "FallingObjectsProperties.h"
#include "GameArea.h"

class Game {
private:
	Scene scene;
	int gameMode;
	FallingObjectsProperties fallingObjectsProperties;
	GameArea& gameArea;

public:
	static const int GAMEMODE_PLAYING = 0;
	static const int GAMEMODE_PAUSED = 1;
	static const int GAMEMODE_RESETING = 2;
	static const int GAMEMODE_QUITING = 3;

	Game(Scene scene, int inititalGameMode, FallingObjectsProperties fallingObjectsProperties, GameArea& gameArea);
	Game(const Game& game);
	Game& operator=(const Game& game);
	~Game();

	Scene getScene();
	void setScene(Scene scene);

	int getGameMode();
	void setGameMode(int gameMode);

	FallingObjectsProperties getFallingObjectsProperties();
	void setFallingObjectsProperties(FallingObjectsProperties fallingObjectsProperties);

	GameArea& getGameArea();
	void setGameArea(GameArea& gameArea);
};
