//
//  Score.cpp
//  ScoreClassGL
//
//  Created by Laura del Pino D�az on 13/5/16.
//  Copyright � 2016 Laura del Pino D�az. All rights reserved.
//

//#include <cstdlib>
#include <sstream>
#include "Score.h"

Score::Score(Coordinates3D position, int score, void* font)
	: Object3D(position),
	score(score),
	font(font) {
}

Score::~Score() {
}

int Score::getScore() {
	return score;
}

void Score::setScore(int score) {
	this->score = score;
}

std::string Score::getScoreString() {
	//std::string num = std::to_string((_Longlong)this->score);
    std::stringstream stream;
	stream << this->score;
	std::string str = stream.str();
	std::string mainText = "Score: ";
	return mainText + str;
}

void Score::increment(int increment) {
	score += increment;
}

void* Score::getFont() {
	return font;
}

void Score::setFont(void* font) {
	this->font = font;
}
