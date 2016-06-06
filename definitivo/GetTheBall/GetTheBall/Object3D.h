#pragma once

#include "Coordinates3D.h"

class Object3D {
protected:
	Coordinates3D position;

public:
	Object3D(Coordinates3D position);
	~Object3D();

	Coordinates3D getPosition();
	void setPosition(Coordinates3D position);

	virtual void draw() = 0;
};
