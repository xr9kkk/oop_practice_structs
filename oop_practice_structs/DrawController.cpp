#include "DrawController.h"

void DrawController::draw_character(Character* character)
{
	std::cout << character->get_name() << " (" << character->get_coordinates()->get_x()
		<< ", " << character->get_coordinates()->get_y() << ") lvl:" <<
		character->get_level() << " hp:" << character->get_hp() << std::endl;
}
