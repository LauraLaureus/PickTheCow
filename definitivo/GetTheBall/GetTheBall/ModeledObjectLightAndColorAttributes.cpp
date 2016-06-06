#include "ModeledObjectLightAndColorAttributes.h"

#include "OpenGLColoring.h"

ModeledObjectLightAndColorAttributes::ModeledObjectLightAndColorAttributes(RGBColor color) 
	: color(color) {
}

ModeledObjectLightAndColorAttributes::~ModeledObjectLightAndColorAttributes() {
}

RGBColor ModeledObjectLightAndColorAttributes::getColor() {
	return color;
}

void ModeledObjectLightAndColorAttributes::setColor(RGBColor color) {
	this->color = color;
}

void ModeledObjectLightAndColorAttributes::applyAtrributes() {
	OpenGLColoring::setMaterialColor(color.getRed(), color.getGreen(), color.getBlue(), color.getDiffuseFactor());
}
