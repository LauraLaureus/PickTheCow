#pragma once

#include "Score.h"

#include "ScoreLightAndColorAttributes.h"

class OGLScore : public Score {
protected:
	ScoreLightAndColorAttributes scoreLightAndColorAttributes;

public:
	OGLScore(Coordinates3D position, int score, void* font, ScoreLightAndColorAttributes scoreLightAndColorAttributes);
	~OGLScore();

	ScoreLightAndColorAttributes getScoreLightAndColorAttributes();
	void setScoreLightAndColorAttributes(ScoreLightAndColorAttributes scoreLightAndColorAttributes);

	virtual void draw();
};
