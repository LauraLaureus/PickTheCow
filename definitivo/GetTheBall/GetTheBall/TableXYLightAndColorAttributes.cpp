#include "TableXYLightAndColorAttributes.h"

#include "OpenGLColoring.h"

TableXYLightAndColorAttributes::TableXYLightAndColorAttributes(RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor)
	: cellColor1(cellColor1),
	cellColor2(cellColor2), 
	homeColor(homeColor) {
}

TableXYLightAndColorAttributes::~TableXYLightAndColorAttributes() {
}

void TableXYLightAndColorAttributes::applyAttributes(RGBColor color) {
	OpenGLColoring::setMaterialColor(color.getRed(), color.getGreen(), color.getBlue(), color.getDiffuseFactor());
}

RGBColor TableXYLightAndColorAttributes::getCellColor1() {
	return cellColor1;
}

void TableXYLightAndColorAttributes::setCellColor1(RGBColor cellColor1) {
	this->cellColor1 = cellColor1;
}

RGBColor TableXYLightAndColorAttributes::getCellColor2() {
	return cellColor2;
}

void TableXYLightAndColorAttributes::setCellColor2(RGBColor cellColor2) {
	this->cellColor2 = cellColor2;
}

RGBColor TableXYLightAndColorAttributes::getHomeColor() {
	return homeColor;
}

void TableXYLightAndColorAttributes::setHomeColor(RGBColor homeColor) {
	this->homeColor = homeColor;
}

void TableXYLightAndColorAttributes::applyCellColor1Attributes() {
	applyAttributes(cellColor1);
}

void TableXYLightAndColorAttributes::applyCellColor2Attributes() {
	applyAttributes(cellColor2);
}

void TableXYLightAndColorAttributes::applyHomeColor1Attributes() {
	applyAttributes(homeColor);
}
