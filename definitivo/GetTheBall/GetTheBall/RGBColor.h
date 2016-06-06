#pragma once

class RGBColor {
private:
	float red;
	float green;
	float blue;
	float diffuseFactor;

public:
	RGBColor(float red, float green, float blue, float diffuseFactor);
	~RGBColor();
	 
	float getRed();
	void setRed(float red);

	float getGreen();
	void setGreen(float green);

	float getBlue();
	void setBlue(float blue);

	float getDiffuseFactor();
	void setDiffuseFactor(float diffuseFactor);
};
