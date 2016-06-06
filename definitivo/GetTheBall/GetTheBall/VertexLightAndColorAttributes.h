#pragma once

#include "LightAndColorAttributes.h"

#include "RGBColor.h"

class VertexLightAndColorAttributes : public LightAndColorAttributes {
protected:
	RGBColor color;

public:
	VertexLightAndColorAttributes(RGBColor color);
	~VertexLightAndColorAttributes();

	RGBColor getColor();
	void setColor(RGBColor color);

	void applyAtrributes();
};
