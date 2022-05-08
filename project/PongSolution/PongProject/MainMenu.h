#pragma once
#include "ColorfulGameItem.h"

class MainMenu : public ColorfulGameItem {
private:
	float title_x;
	float title_y;
	float title_size;
	string title;


	float space_to_start_x;
	float space_to_start_y;
	float space_to_start_size;
	string space_to_start;

	float esc_to_exit_x;
	float esc_to_exit_y;
	float esc_to_exit_size;
	string esc_to_exit;
public:
	MainMenu();

	virtual void start();
	virtual void draw();
	virtual void move();
};

