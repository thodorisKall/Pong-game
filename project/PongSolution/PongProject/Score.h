#pragma once
#include "ColorfulGameItem.h"

class Score : public ColorfulGameItem {
public:
	int scoreForPlayer1;
	int scoreForPlayer2;
	float x, y;
	float size;

	Score();

	int getLevel();

	virtual void start();
	virtual void draw();
	virtual void move();
};

