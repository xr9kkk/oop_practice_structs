#include "Character.h"
#include <cmath>

Character::Character(std::string name, Coordinates* c, int level, int hp)
{
	this->name = name;
	this->coordinates = c;
	this->level = level;
	this ->hp = hp;
}

Character::~Character()
{
	delete coordinates;
}

Character* Character::spawn_copy()
{
	int spawn_radius = this->spawn_radius;
	int copy_x_d{ rand() % (2 * spawn_radius) - spawn_radius };
	int copy_y_d{ static_cast<int>(std::sqrt(std::pow(spawn_radius, 2) - std::pow(copy_x_d, 2))) };
	std::string copy_name{ this->name + "_copy" };

	Character* copy_character{ new Character(copy_name, new Coordinates(
		this->coordinates->get_x() + copy_x_d,
		this->coordinates->get_y() + copy_y_d),
		this->level,
		this->hp) };

	return copy_character;
}



Character* Character::attack(std::vector<Character*> l)
{
	if (l.size() > 1)
	{
		Character* target = nullptr;
		float target_dist{ FLT_MAX };
		for (Character* c : l) {
			if (this != c)
			{
				float c_dist{ this->coordinates->distance(c->coordinates) };
				if (target == nullptr || c_dist < target_dist ||
					c_dist == target_dist && c->level < target->level ||
					c_dist == target_dist && c->level == target->level && c->hp < target->hp)
				{
					target = c;
					target_dist = c_dist;
				}
					
			}
		}
		target->hp -= this->level;
		return target;
			
	}
	return nullptr;
}
