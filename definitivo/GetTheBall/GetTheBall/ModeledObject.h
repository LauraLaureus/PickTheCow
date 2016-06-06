#pragma once

#include "Object3D.h"
#include "Coordinates3D.h"
#include "IModelFormat.h"

class ModeledObject : public Object3D {
protected:
	IModelFormat* model;
	char* fileName;

public:
	ModeledObject(Coordinates3D position, IModelFormat* model);
	ModeledObject(const ModeledObject& modeledObject);
	ModeledObject& operator=(const ModeledObject& modeledObject);
	~ModeledObject();

	IModelFormat* getModel();
	void setModel(IModelFormat* model);
};
