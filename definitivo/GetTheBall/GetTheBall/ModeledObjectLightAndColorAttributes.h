#pragma once

#include "LightAndColorAttributes.h"

#include "RGBColor.h"

class ModeledObjectLightAndColorAttributes : public LightAndColorAttributes {
protected:
	RGBColor color;

public:
	ModeledObjectLightAndColorAttributes(RGBColor color);
	~ModeledObjectLightAndColorAttributes();

	RGBColor getColor();
	void setColor(RGBColor color);

	void applyAtrributes();
};
