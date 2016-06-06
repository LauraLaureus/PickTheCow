#include "ScoreLightAndColorAttributes.h"

#include "OpenGLColoring.h"

ScoreLightAndColorAttributes::ScoreLightAndColorAttributes(RGBColor color)
	: color(color) {
}

ScoreLightAndColorAttributes::~ScoreLightAndColorAttributes() {
}

RGBColor ScoreLightAndColorAttributes::getColor() {
	return color;
}

void ScoreLightAndColorAttributes::setColor(RGBColor color) {
	this->color = color;
}

void ScoreLightAndColorAttributes::applyAtrributes() {
	OpenGLColoring::setMaterialColor(color.getRed(), color.getGreen(), color.getBlue(), color.getDiffuseFactor());
}
