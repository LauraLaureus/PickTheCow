#pragma once

#include "Object3D.h"

class User {
protected:
	Object3D& object3D;
	double maxCatchDistance;

public:
	User(Object3D& object3D, double maxCatchDistance);
	User(const User& user);
	User& operator=(const User& user);
	~User();

	Object3D& getObject3D();
	void setObject3D(Object3D& object3D);

	double getMaxCatchDistance();
	void setMaxCatchDistance(double maxCatchDistance);
};
