#pragma once
#include <string>
#include "ColorfulGameItem.h"

using namespace std;

class GameOver : public ColorfulGameItem {
private:
	float title_x;
	float title_y;
	float title_size;
	string title;


	float p1_wins_x;
	float p1_wins_y;
	float p1_wins_size;
	string p1_wins;

	float p2_wins_x;
	float p2_wins_y;
	float p2_wins_size;
	string p2_wins;
	
public:
	int state;
	GameOver();

	virtual void start();
	virtual void draw();
	virtual void move();
};

