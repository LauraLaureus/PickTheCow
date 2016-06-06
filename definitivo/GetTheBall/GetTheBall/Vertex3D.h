#pragma once

#include "Object3D.h"
#include "Coordinates3D.h"

class Vertex3D : public Object3D {

public:
	Vertex3D(Coordinates3D position);
	~Vertex3D();
};
