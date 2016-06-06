#include "User.h"

User::User(Object3D& object3D, double maxCatchDistance)
	: object3D(object3D),
	maxCatchDistance(maxCatchDistance) {
}

User::User(const User& user) 
	: object3D(user.object3D),
	maxCatchDistance(user.maxCatchDistance) {

}

User& User::operator=(const User& user) {

	if (this != &user) {
		this->object3D = user.object3D;
		this->maxCatchDistance = user.maxCatchDistance;
	}

	return *this;
}

User::~User() {
}

Object3D& User::getObject3D() {
	return object3D;
}

void User::setObject3D(Object3D& object3D) {
	this->object3D = object3D;
}

double User::getMaxCatchDistance() {
	return maxCatchDistance;
}

void User::setMaxCatchDistance(double maxCatchDistance) {
	this->maxCatchDistance;
}
