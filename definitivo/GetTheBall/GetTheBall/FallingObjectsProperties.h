#pragma once

#include "Coordinates3D.h"
class FallingObjectsProperties {
private:
	int maximunQuantity;
	int creationPeriod;
	int updatingPeriod;
	double fallingDistanceIncrement;
	double minimunDistanceToFloor;

public:
	FallingObjectsProperties(int maximunQuantity, int creationPeriod, int updatingPeriod, double positionIncrement, double minimunDistanceToFloor);
	~FallingObjectsProperties();

	unsigned int getMaximunQuantity();
	void setMaximunQuantity(unsigned int maximunQuantity);

	int getCreationPeriod();
	void setCreationPeriod(int creationPeriod);

	int getUpdatingPeriod();
	void setUpdatingPeriod(int updatingPeriod);

	double getFallingDistanceIncrement();
	void setFallingDistanceIncrement(double positionIncrement);

	double getMinimunDistanceToFloor();
	void setMinimunDistanceToFloor(double minimunDistanceToFloor);
};
