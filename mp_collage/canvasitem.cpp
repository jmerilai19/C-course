/**
 * Copyright 2024 University of Oulu
 * Authors:
 *   Elmeri Uotila <roope.uotila@oulu.fi>
 */

#include "canvasitem.h"

CanvasItem::CanvasItem(size_t x, size_t y, Vector2 position, Vector2 scale, RGBAPixel color) {
	resize(x, y);
	// TODO Initialize the pixels transparent so when drawing shapes, the background is transparent
	// Your code here

	for (size_t i = 0; i < width(); ++i) {
        for (size_t j = 0; j < height(); ++j) {
            RGBAPixel* pixel = (*this)(i, j);
            pixel->red = 255;   // Set default red channel to full intensity
            pixel->green = 255; // Set default green channel to full intensity
            pixel->blue = 255;  // Set default blue channel to full intensity
            pixel->alpha = 0;    // Set default alpha channel to fully transparent
        }
    }

	position_ = position;
	color_ = color;
	scale_ = scale;
}

RGBAPixel CanvasItem::getBlendedPixel(size_t x, size_t y){
	RGBAPixel* p = (*this)(x,y);
	RGBAPixel copy = *p;
	// TODO Blend the pixel with color_
	// Multiply the colors per channel and divide by 255
	// Result should be stored in a copy so we don't modify the original PNG
	// This way the color can be easily changed later

	// Your code here
	
	copy.red = (p->red * color_.red) / 255;
    copy.green = (p->green * color_.green) / 255;
    copy.blue = (p->blue * color_.blue) / 255;
    copy.alpha = (p->alpha * color_.alpha) / 255;

	return copy;
}

Vector2 CanvasItem::position(){
	return position_;
}

Vector2 CanvasItem::scale(){
	return scale_;
}

void CanvasItem::SetPosition(Vector2 pos){
	position_ = pos;
}