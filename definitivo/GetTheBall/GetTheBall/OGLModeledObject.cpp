#include "OGLModeledObject.h"

#include <GLUT/GLUT.h>
OGLModeledObject::OGLModeledObject(Coordinates3D position, IModelFormat* model, ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes, double scaleFactor)
	: ModeledObject(position, model),
	modeledObjectLightAndColorAttributes(modeledObjectLightAndColorAttributes),
	scaleFactor(scaleFactor) {
}

OGLModeledObject::OGLModeledObject(const OGLModeledObject& oGLModeledObject)
	: ModeledObject(oGLModeledObject.position, oGLModeledObject.model),
	modeledObjectLightAndColorAttributes(oGLModeledObject.modeledObjectLightAndColorAttributes),
	scaleFactor(scaleFactor) {
}

OGLModeledObject& OGLModeledObject::operator=(const OGLModeledObject& oGLModeledObject) {
	if (this != &oGLModeledObject) {
		ModeledObject::operator=(oGLModeledObject);
		this->modeledObjectLightAndColorAttributes = oGLModeledObject.modeledObjectLightAndColorAttributes;
		this->scaleFactor = oGLModeledObject.scaleFactor;
	}

	return *this;
}

OGLModeledObject::~OGLModeledObject() {
}

void OGLModeledObject::draw() {
	modeledObjectLightAndColorAttributes.applyAtrributes();

	glPushMatrix();
		glTranslated(position.getX(), position.getY(), position.getZ());
		glScaled(scaleFactor, scaleFactor, scaleFactor);
		model->Draw();
	glPopMatrix();
}

ModeledObjectLightAndColorAttributes OGLModeledObject::getModeledObjectLightAndColorAttributes() {
	return modeledObjectLightAndColorAttributes;
}

void OGLModeledObject::setModeledObjectLightAndColorAttributes(ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes) {
	this->modeledObjectLightAndColorAttributes = modeledObjectLightAndColorAttributes;
}

double OGLModeledObject::getScaleFactor() {
	return scaleFactor;
}

void OGLModeledObject::setScaleFactor(double scaleFactor) {
	this->scaleFactor = scaleFactor;
}
