#include "GameOver.h"

#include <string>

#include "graphics.h"

using namespace std;

GameOver::GameOver() : ColorfulGameItem(0,1,0) {
	title_x = 25;
	title_y = 40;
	title_size = 12;
	title = "GAME OVER";

	p1_wins_x = 35;
	p1_wins_y = 60;
	p1_wins_size = 5;

	p2_wins_x = 35;
	p2_wins_y = 60;
	p2_wins_size = 5;

	p1_wins = "player 1 wins!!!";
	p2_wins = "player 2 wins!!!";
}

void GameOver::draw() {
	graphics::Brush br;
	colorize(br);
	
	graphics::setFont("assets/abc.ttf");
	 
	if (state == 2 || state == 3) {
		graphics::drawText(title_x, title_y, title_size, title, br);
	}
	if (state == 2) {
		graphics::drawText(p1_wins_x, p1_wins_y, p1_wins_size, p1_wins, br);
	}

	if (state == 3) {
		graphics::drawText(p2_wins_x, p2_wins_y, p2_wins_size, p2_wins, br);
	}

	
}

void GameOver::start() {

}

void GameOver::move() {

}