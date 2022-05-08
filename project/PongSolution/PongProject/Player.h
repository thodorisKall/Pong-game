#pragma once
#include "ColorfulGameItem.h"

class Player : public ColorfulGameItem {
public:
	int id;
	float x, y;
	float width, height;
	float lower_bound_y;
	float upper_bound_y;
	float speed;

	Player(int id);

	virtual void start();
	virtual void draw();
	virtual void move();
};

