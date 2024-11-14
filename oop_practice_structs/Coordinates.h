#pragma once

#include <cmath>
#include <iostream>

class Coordinates
{
private:
	int x{}, y{};
public:
	Coordinates(int x, int y);
	Coordinates() : Coordinates(0, 0) {};
	Coordinates(Coordinates* c);
	int get_x() { return  x; }
	int get_y() { return y; }
	float distance(Coordinates* c);
};

