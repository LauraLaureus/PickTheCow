#include "EuclideanDistance.h"

#include "math.h"

double EuclideanDistance::solve(Coordinates3D a, Coordinates3D b) {
	return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2) + pow(a.getZ() - b.getZ(), 2));
}