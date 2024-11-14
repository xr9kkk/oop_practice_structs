#include "Coordinates.h"


Coordinates::Coordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

Coordinates::Coordinates(Coordinates* c)
{
    this->x = c->x;
    this->y = c->y;
}

float Coordinates::distance(Coordinates* c)
{
    return std::sqrt(std::pow(c->x - this->x, 2) + std::pow(c->y - this->y, 2));
}
