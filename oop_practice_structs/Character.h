#pragma once
#include <string>
#include"Coordinates.h"
#include <vector>


class Character
{
private:
	std::string name;
	Coordinates* coordinates;
	int level{}, hp{};
	const int spawn_radius{ 20 };
public:
	Character(std::string name, Coordinates* c, int level, int hp);
	~Character();
	std::string get_name() { return name; };
	Coordinates* get_coordinates() { return coordinates;};
	int get_level() { return level; };
	int get_hp() { return hp;};
	Character* spawn_copy();
	Character* attack(std::vector<Character*> l);
};

