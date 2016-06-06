#pragma once

#include "Vertex3D.h"
#include "VertexLightAndColorAttributes.h"

class OGLVertex3D : public Vertex3D {
protected:
	VertexLightAndColorAttributes vertexLightAndColorAttributes;

public:
	OGLVertex3D(Coordinates3D position, VertexLightAndColorAttributes vertexLightAndColorAttributes);
	~OGLVertex3D();

	VertexLightAndColorAttributes getVertexLightAndColorAttributes();
	void setVertexLightAndColorAttributes(VertexLightAndColorAttributes vertexLightAndColorAttributes);

	virtual void draw();
};

