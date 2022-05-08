#include "Score.h"
#include "Game.h"
#include "graphics.h"

using namespace std;

Score::Score() : ColorfulGameItem(1,1,0) {
	x = 35;
	y = 10;
	size = 5;

	scoreForPlayer1 = 0;
	scoreForPlayer2 = 0;
}

void Score::start() {
	scoreForPlayer1 = 0;
	scoreForPlayer2 = 0;		 
}

void Score::move() {
	
}

void Score::draw() {
	Game* game = (Game*)graphics::getUserData();

	string title = "Score   " + std::to_string(scoreForPlayer1) +
		" - " + std::to_string(scoreForPlayer2);

	graphics::Brush br;
	colorize(br);
	graphics::drawText((float)x, (float) y, size, title, br);
}

int Score::getLevel() {
	int m = max(scoreForPlayer1, scoreForPlayer2);

	// m = 0: intro		- max score = 0 ... 1
	// m = 1: prologue	- max score = 2 ... 3
	// m = 2: story		- max score = 4 ... 5
	// m = 3: action	- max score = 6 ... 7
	// m = 4: finalle	- max score = 8 ... 9

	return m / 2;
}