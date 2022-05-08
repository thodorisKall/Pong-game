#include <iostream>
#include <random>
#include <string>
#include "Game.h"
#include "Ball.h"
#include "graphics.h"

#include "vecmath.h"

void update(float ms) {
	Game* game = (Game*)graphics::getUserData();
	game->move();
}

void draw() {
	Game* game = (Game*)graphics::getUserData();	
	game->draw();
}

int main() {	
	Game game;

	graphics::createWindow(game.window_width, game.window_height, "C++ demo");

	game.init();

	graphics::setUserData(&game);
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(game.canvas_width, game.canvas_height);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::startMessageLoop();
	graphics::destroyWindow();

	return 0;
}
