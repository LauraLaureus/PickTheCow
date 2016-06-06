#include "Scene.h"

#include <iostream>

#include "Conversion.h"

Scene::Scene(RoomXY& roomXY, User user, Score& score)
	: roomXY(roomXY),
	user(user),
	score(score) {
	fallingObjects = std::list<FallingObject*>();
}

Scene::Scene(const Scene& scene)
	: roomXY(scene.roomXY),
	user(scene.user),
	score(scene.score) {
	
	this->fallingObjects = std::list<FallingObject*>();
	std::list<FallingObject*> source = scene.fallingObjects;
	for (std::list<FallingObject*>::iterator fallingObject = source.begin(); fallingObject != source.end(); ++fallingObject) {
		this->fallingObjects.push_back(*fallingObject);
	}
}

Scene& Scene::operator=(const Scene& scene) {

	if (this != &scene) {
		this->roomXY = scene.roomXY;
		this->user = scene.user;
		this->score = scene.score;
		
		this->fallingObjects = std::list<FallingObject*>();
		std::list<FallingObject*> source = scene.fallingObjects;
		for (std::list<FallingObject*>::iterator fallingObject = source.begin(); fallingObject != source.end(); ++fallingObject) {
			this->fallingObjects.push_back(*fallingObject);
		}
		fallingObjects = scene.fallingObjects;
	}

	return *this;
}

Scene::~Scene() {
	fallingObjects.clear();
}

RoomXY& Scene::getRoomXY() {
	return roomXY;
}

void Scene::setRoomXY(RoomXY& roomXY) {
	this->roomXY = roomXY;
}

User Scene::getUser() {
	return user;
}

void Scene::setUser(User user) {
	this->user = user;
}

std::list<FallingObject*> Scene::getFallingObjects() {
	return fallingObjects;
}

void Scene::setFallingObjects(std::list<FallingObject*> fallingObjects) {
	this->fallingObjects = fallingObjects;
}

Score& Scene::getScore() {
	return score;
}

void Scene::setScore(Score& score) {
	this->score = score;
}
