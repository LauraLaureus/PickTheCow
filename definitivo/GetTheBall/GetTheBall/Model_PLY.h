/*
Clase de carga de modelos PLY.
Adaptado desde http://openglsamples.sourceforge.net/files/glut_ply.cpp
por Juan Mendez para CIU
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <GLUT/GLUT.h>
#include <cmath>
#include <string>

#include "IModelFormat.h"

class Model_PLY : public IModelFormat
{
public:
	Model_PLY();
	virtual int Load(char *filename);
	virtual void Draw();
	void calculateNormal(float *coord1, float *coord2, float *coord3);

	float* Faces_Triangles;
	float* Faces_Quads;
	float* Vertex_Buffer;
	float* Normals;

	int TotalConnectedTriangles;
	int TotalConnectedQuads;
	int TotalConnectedPoints;
	int TotalFaces;

	float norm[3]; // almacen temporal
};