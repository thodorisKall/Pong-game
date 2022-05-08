#include "Player.h"
#include <graphics.h>

Player::Player(int id) : ColorfulGameItem(0.5f, 0.7f, (id == 1) ? 0.9f : 0.0f), id(id) {
	if (id == 1) {
		x = 5;
		y = 50;		
	} else {
		x = 95;
		y = 50;
	}

	width = 3;
	height = 15;
	lower_bound_y = 10;
	upper_bound_y = 90;
	speed = 0.5;
}

void Player::start() {
	if (id == 1) {
		x = 5;
		y = 50;
	}
	else {
		x = 95;
		y = 50;
	}
}

void Player::move() {

	if (id == 1) {
		if (graphics::getKeyState(graphics::SCANCODE_Q)) {
			if (y > lower_bound_y) {
				y= y - speed;
			}
		}

		if (graphics::getKeyState(graphics::SCANCODE_A)) {
			if (y < upper_bound_y) {
				y=y+ speed;
			}
		}
	} else {
		if (graphics::getKeyState(graphics::SCANCODE_P)) {
			if (y > lower_bound_y) {
				y=y- speed;
			}
		}
		if (graphics::getKeyState(graphics::SCANCODE_L)) {
			if (y < upper_bound_y) {
				y=y+ speed;
			}
		}

	}

}

void Player::draw() {
	graphics::Brush br;

	colorize(br);
	
	graphics::drawRect(x, y, width, height, br);

	graphics::resetPose();
}
