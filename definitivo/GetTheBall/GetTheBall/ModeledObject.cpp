#include "ModeledObject.h"

ModeledObject::ModeledObject(Coordinates3D position, IModelFormat* model)
	: Object3D(position), 
	model(model) {
}

ModeledObject::ModeledObject(const ModeledObject& modeledObject) 
	: Object3D(position),
	model(model) {
}

ModeledObject& ModeledObject::operator=(const ModeledObject& modeledObject) {
	if (this != &modeledObject) {
		position = modeledObject.position;
		model = modeledObject.model;
	}

	return *this;
}

ModeledObject::~ModeledObject() {
}

IModelFormat* ModeledObject::getModel() {
	return model;
}

void ModeledObject::setModel(IModelFormat* model) {
	this->model = model;
}
