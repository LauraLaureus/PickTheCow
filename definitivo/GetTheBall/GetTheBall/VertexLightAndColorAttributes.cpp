#include "VertexLightAndColorAttributes.h"

#include "OpenGLColoring.h"

VertexLightAndColorAttributes::VertexLightAndColorAttributes(RGBColor color)
	: color(color) {
}

VertexLightAndColorAttributes::~VertexLightAndColorAttributes() {
}

RGBColor VertexLightAndColorAttributes::getColor() {
	return color;
}

void VertexLightAndColorAttributes::setColor(RGBColor color) {
	this->color = color;
}

void VertexLightAndColorAttributes::applyAtrributes() {
	OpenGLColoring::setMaterialColor(color.getRed(), color.getGreen(), color.getBlue(), color.getDiffuseFactor());
}
