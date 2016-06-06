#include "OGLVertex3D.h"

#include <GLUT/GLUT.h>

OGLVertex3D::OGLVertex3D(Coordinates3D position, VertexLightAndColorAttributes vertexLightAndColorAttributes)
	: Vertex3D(position),
	vertexLightAndColorAttributes(vertexLightAndColorAttributes) {
}

OGLVertex3D::~OGLVertex3D() {
}

VertexLightAndColorAttributes OGLVertex3D::getVertexLightAndColorAttributes() {
	return vertexLightAndColorAttributes;
}

void OGLVertex3D::setVertexLightAndColorAttributes(VertexLightAndColorAttributes vertexLightAndColorAttributes) {
	this->vertexLightAndColorAttributes = vertexLightAndColorAttributes;
}

void OGLVertex3D::draw() {
	glVertex3d(position.getX(), position.getY(), position.getZ());
}
