#include "OGLScore.h"

#include <GLUT/GLUT.h>
OGLScore::OGLScore(Coordinates3D position, int score, void* font, ScoreLightAndColorAttributes scoreLightAndColorAttributes) 
	:Score(position, score, font),
	scoreLightAndColorAttributes(scoreLightAndColorAttributes) {
}

OGLScore::~OGLScore() {
}

ScoreLightAndColorAttributes OGLScore::getScoreLightAndColorAttributes() {
	return scoreLightAndColorAttributes;
}

void OGLScore::setScoreLightAndColorAttributes(ScoreLightAndColorAttributes scoreLightAndColorAttributes) {
	this->scoreLightAndColorAttributes = scoreLightAndColorAttributes;
}

void OGLScore::draw() {
	glPushMatrix();
	scoreLightAndColorAttributes.applyAtrributes();

	glRasterPos3d(position.getX(), position.getY(), position.getZ());
	std::string scorestring = getScoreString();
	for (unsigned int i = 0; i < scorestring.size(); i++) {
		glutBitmapCharacter(font, scorestring[i]);
	}
	glPopMatrix();
}
