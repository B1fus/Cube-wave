#pragma once
#include "Points vectors.h"

enum { MOUSE_LEFT = 0b1, MOUSE_MIDDLE = 0b10, MOUSE_RIGHT = 0b100, MOUSE_X1 = 0b1000, MOUSE_X2 = 0b10000 };

struct Mouse
{
	Point2<int> coords;
	Point2<int> prevCoords;
	uint8_t buttons = 0;
	int8_t wheel = 0;


	Mouse();
};


struct Keyboard {
	bool keys[256] = { 0 };

	Keyboard();
	void clear();
};