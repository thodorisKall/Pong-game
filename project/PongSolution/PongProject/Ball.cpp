#include <random>
#include "Ball.h"
#include "graphics.h"
#include "vecmath.h"
#include "ColorfulGameItem.h"

using namespace std;
using namespace math;

#include "Game.h"

Ball::Ball() : ColorfulGameItem(1.0f,1.0f,1.0f, 0.5f, 0.0f){
	x = 50.0f;
	y = 50.0f;
	radius = 4.0f;
	direction_x = 1.0f;
	direction_y = 0.0f;
	speed = 0.5;
}

void Ball::start() {
	random_device seed;
	default_random_engine generator(seed());
	uniform_real_distribution<float> distribution(-1.0, 1.0);

	x = 50.0f;
	y = 50.0f;
	direction_x = distribution(generator);
	direction_y = distribution(generator);

	if (fabs(direction_x) < 0.5) {
		direction_x = direction_x * 2;
	}
}

void Ball::draw() {
	graphics::Brush br;

	colorize(br);
	br.texture = "assets/waves.png";

	graphics::drawDisk(x, y, radius, br);
}

// CIRCLE/RECTANGLE
bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) {

	// temporary variables to set edges for testing
	float testX = cx;
	float testY = cy;

	// which edge is closest?
	if (cx < rx)         testX = rx;      // test left edge
	else if (cx > rx + rw) testX = rx + rw;   // right edge
	if (cy < ry)         testY = ry;      // top edge
	else if (cy > ry + rh) testY = ry + rh;   // bottom edge

	// get distance from closest edges
	float distX = cx - testX;
	float distY = cy - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the radius, collision!
	if (distance <= radius) {
		return true;
	}
	return false;
}

bool Ball::checkOverlap(Player& p, float Xc, float Yc) {
	return circleRect(Xc, Yc, radius, p.x - p.width/2, p.y - p.height/2, p.width, p.height);
}
void Ball::move() {
	Game* game = (Game*)graphics::getUserData();
	
	float ball_future_center_x = x + direction_x * speed;
	float ball_future_center_y = y + direction_y * speed;
	
	status = "normal";

	if (checkOverlap(game->p1, x, y)) {		
		direction_x = fabs(direction_x);
		x = game->p1.x + game->p1.width + radius;
		status = "p1_overlap";
		string wav = "assets/touch.wav";
		graphics::playSound(wav, 1.0f);
	} else if (checkOverlap(game->p2, x, y)) {
		direction_x = -fabs(direction_x);
		x = game->p2.x - game->p2.width - radius;
		status = "p2_overlap";
		string wav = "assets/touch.wav";
		graphics::playSound(wav, 1.0f);
	}

	if ((ball_future_center_x + radius) >= game->canvas_width) {
		// collision with right border
		vec2 dir{ direction_x, direction_y };
		vec2 normal = { -1.0f, 0.0f };
		vec2 reflection = reflect(dir, normal);
		direction_x = reflection.x;
		direction_y = reflection.y;
		status = "right";
	} else if ((ball_future_center_x - radius) <= 0.0f) {
		// collision with left border
		vec2 dir{ direction_x, direction_y };
		vec2 normal = { 1.0f, 0.0f };
		vec2 reflection = reflect(dir, normal);
		direction_x = reflection.x;
		direction_y = reflection.y;
		status = "left";
	}

	if ((ball_future_center_y + radius) >= game->canvas_height) {
		// collision with bottom boder
		vec2 dir{ direction_x, direction_y };
		vec2 normal = { 0.0f, -1.0f };
		vec2 reflection = reflect(dir, normal);
		direction_x = reflection.x;
		direction_y = reflection.y;
		status = "bottom";
	} else if ((ball_future_center_y - radius) <= 0.0f) {
		// collision with top border
		vec2 dir{ direction_x, direction_y };
		vec2 normal = { 0.0f, 1.0f };
		vec2 reflection = reflect(dir, normal);
		direction_x = reflection.x;
		direction_y = reflection.y;	
		status = "top";
	}

	if (status== "top" || status == "bottom") {
		string wav = "assets/hit_border.wav";
		graphics::playSound(wav, 1.0f);
	}

	if (status == "left" || status == "right") {
		string wav = "assets/hit_ball.wav";
		graphics::playSound(wav, 1.0f);
	}

	x += direction_x * speed;
	y += direction_y * speed;
}