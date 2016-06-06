//
//  Score.hpp
//  ScoreClassGL
//
//  Created by Laura del Pino Díaz on 13/5/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#pragma once

#include <string>

#include "Object3D.h"

class Score : public Object3D
{
protected:
	int score;
	void* font;

public:
	Score(Coordinates3D position, int score, void* font);
	~Score();

	int getScore();
	void setScore(int score);

	void* getFont();
	void setFont(void* font);

	std::string getScoreString();
	void increment(int increment);
};
