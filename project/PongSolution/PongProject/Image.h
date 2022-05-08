#pragma once
#include <string>
#include "ColorfulGameItem.h"

using namespace std;

class Image : public ColorfulGameItem {
	string path;
	float x, y;
	float width, height;

public:	
	Image(string path, float x, float y, float width, float height);

	virtual void start();
	virtual void move();
	virtual void draw();
};

