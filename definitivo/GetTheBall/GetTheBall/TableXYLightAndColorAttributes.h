#pragma once

#include "LightAndColorAttributes.h"

#include "RGBColor.h"

class TableXYLightAndColorAttributes : public LightAndColorAttributes {
protected:
	RGBColor cellColor1;
	RGBColor cellColor2;
	RGBColor homeColor;

public:
	TableXYLightAndColorAttributes(RGBColor cellColor1, RGBColor cellColor2, RGBColor homeColor);
	~TableXYLightAndColorAttributes();

	RGBColor getCellColor1();
	void setCellColor1(RGBColor cellColor1);

	RGBColor getCellColor2();
	void setCellColor2(RGBColor cellColor2);

	RGBColor getHomeColor();
	void setHomeColor(RGBColor homeColor);

	void applyCellColor1Attributes();
	void applyCellColor2Attributes();
	void applyHomeColor1Attributes();
	void applyAttributes(RGBColor color);
};
