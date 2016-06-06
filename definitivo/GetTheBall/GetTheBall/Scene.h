#pragma once

#include <list>

#include "RoomXY.h"
#include "User.h"
#include "Score.h"
#include "FallingObject.h"

class Scene {
protected:
	RoomXY& roomXY;
	User user;
	std::list<FallingObject*> fallingObjects;
	Score& score;

public:
	Scene(RoomXY& roomXY, User user, Score& score);
	Scene(const Scene& scene);
	Scene& operator=(const Scene& scene);
	~Scene();

	RoomXY& getRoomXY();
	void setRoomXY(RoomXY& roomXY);

	User getUser();
	void setUser(User user);

	std::list<FallingObject*> getFallingObjects();
	void setFallingObjects(std::list<FallingObject*> fallingObjects);

	Score& getScore();
	void setScore(Score& score);
};
