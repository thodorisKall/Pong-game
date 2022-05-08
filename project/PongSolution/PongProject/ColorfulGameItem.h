#pragma once
#include "graphics.h"
#include "GameItem.h"

class ColorfulGameItem : public GameItem {
public:
	float red, green, blue, fill_opacity, outline_opacity;

	ColorfulGameItem(float red, float green, float blue, 
		float fill_opacity = 1.0f, float outline_opacity = 0.0f);

	void colorize(graphics::Brush & br);
};

