#pragma once

#include "LightAndColorAttributes.h"

#include "RGBColor.h"

class ScoreLightAndColorAttributes : public LightAndColorAttributes {
protected:
	RGBColor color;

public:
	ScoreLightAndColorAttributes(RGBColor color);
	~ScoreLightAndColorAttributes();

	RGBColor getColor();
	void setColor(RGBColor color);

	void applyAtrributes();
};
