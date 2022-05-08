#include <string>

using namespace std;


#include "MainMenu.h"
#include "graphics.h"

MainMenu::MainMenu() : ColorfulGameItem(0,128,128) {
	title_x = 15;
	title_y = 40;
	title_size = 20;
	title = " P O N G";

	space_to_start_x = 23;
	space_to_start_y = 70;
	space_to_start_size = 5;

	esc_to_exit_x = 30;
	esc_to_exit_y= 80;
	esc_to_exit_size = 5;

	space_to_start = "press 'space' to start";
	esc_to_exit = "press 'esc' to exit";
}

void MainMenu::draw() {
	graphics::Brush br;
	colorize(br);

	graphics::setFont("assets/retroFont.ttf");

	graphics::drawText(title_x, title_y, title_size, title, br);
	graphics::drawText(space_to_start_x, space_to_start_y, space_to_start_size, space_to_start, br);
	graphics::drawText(esc_to_exit_x, esc_to_exit_y, esc_to_exit_size, esc_to_exit, br);
}

void MainMenu::start() {

}


void MainMenu::move() {

}