#include "Image.h"
#include <graphics.h>

Image::Image(string path, float x, float y, float width, float height) : ColorfulGameItem(0.5f, 0.7f,0.9f), x(x),y(y), path(path), width(width), height(height)
{
}

void Image::start() {
			
}

void Image::move() {
	
}

void Image::draw() {
	graphics::Brush br;

	colorize(br);	

	br.texture = path;

	graphics::drawRect(x, y, width, height, br);
}