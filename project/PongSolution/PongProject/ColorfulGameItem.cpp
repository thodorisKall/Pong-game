#include "ColorfulGameItem.h"
#include "graphics.h"

ColorfulGameItem::ColorfulGameItem(float red, float green, 
	float blue, float fill_opacity, float outline_opacity) 
	: red(red), green(green), blue(blue), fill_opacity(fill_opacity), outline_opacity(outline_opacity)
{
}

void ColorfulGameItem::colorize(graphics::Brush & br) {
	br.fill_color[0] = red;
	br.fill_color[1] = green;
	br.fill_color[2] = blue;
	
	br.fill_opacity = fill_opacity;
	br.outline_opacity = outline_opacity;	
}
