#include "RGBColor.h"

RGBColor::RGBColor(float red, float green, float blue, float diffuseFactor)
	: red(red),
	green(green),
	blue(blue),
	diffuseFactor(diffuseFactor){
}

RGBColor::~RGBColor() {
}

float RGBColor::getRed() {
	return red;
}

void RGBColor::setRed(float red) {
	this->red = red;
}

float RGBColor::getGreen() {
	return green;
}

void RGBColor::setGreen(float green) {
	this->green = green;
}

float RGBColor::getBlue() {
	return blue;
}

void RGBColor::setBlue(float blue) {
	this->blue = blue;
}

float RGBColor::getDiffuseFactor() {
	return diffuseFactor;
}

void RGBColor::setDiffuseFactor(float diffuseFactor) {
	this->diffuseFactor = diffuseFactor;
}
