#pragma once

class Coordinates3D {
private:
	double x;
	double y;
	double z;


public:
	Coordinates3D(double x, double y, double z);
	~Coordinates3D();

	double getX();
	void setX(double x);

	double getY();
	void setY(double y);

	double getZ();
	void setZ(double z);

	bool equals(Coordinates3D coordinates3D);
};
