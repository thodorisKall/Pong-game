#pragma once
#include <string>
#include "Player.h"
#include "ColorfulGameItem.h"

using namespace std;

class Ball : public ColorfulGameItem {
public:
	float x;
	float y;
	float radius;
	float direction_x;
	float direction_y;
	float speed;
	string status;

	Ball();

	virtual void start();
	virtual void draw();
	virtual void move();

	bool checkOverlap(Player & p, float Xc, float Yc);
};

