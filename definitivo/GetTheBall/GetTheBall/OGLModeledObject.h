#pragma once

#include "ModeledObject.h"

#include "ModeledObjectLightAndColorAttributes.h"

class OGLModeledObject : public ModeledObject {
protected:
	ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes;
	double scaleFactor;

public:
	OGLModeledObject(Coordinates3D position, IModelFormat* model, ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes, double scaleFactor);
	OGLModeledObject(const OGLModeledObject& oGLModeledObject);
	OGLModeledObject& operator=(const OGLModeledObject& oGLModeledObject);
	~OGLModeledObject();

	ModeledObjectLightAndColorAttributes getModeledObjectLightAndColorAttributes();
	void setModeledObjectLightAndColorAttributes(ModeledObjectLightAndColorAttributes modeledObjectLightAndColorAttributes);

	double getScaleFactor();
	void setScaleFactor(double scaleFactor);

	virtual void draw();
};
