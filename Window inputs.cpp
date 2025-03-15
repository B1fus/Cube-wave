#include "Window inputs.h"

Mouse::Mouse()
{
	coords = { 0,0 };
	prevCoords = { 0,0 };
}

Keyboard::Keyboard() {
}

void Keyboard::clear() {
	memset(keys, 0, sizeof(keys[0]) * 256);
}