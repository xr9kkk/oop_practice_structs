#include <iostream>
#include <vector>
#include "Character.h"
#include "DrawController.h"
#include <thread>

int main()
{
	using namespace std::chrono_literals;
	srand(time(NULL));
	std::vector<Character*>l;
	l.push_back(new Character("1", new Coordinates(0, 0), 10, 20));
	l.push_back(new Character("2", new Coordinates(10, 0), 5, 15));
	l.push_back(new Character("3", new Coordinates(50, 20), 1, 30));
	l.push_back(new Character("4", new Coordinates(100, -20), 20, 20));

	DrawController* dc = new DrawController();
	for (Character* c : l) {
		dc->draw_character(c);
	}
	for (int i{}; i<10; ++i)
	{
		std::vector<Character*> copies;
		for (int i{ 0 }; i < l.size(); ++i)
		{
			if (rand() % 100 < 25)
			{
				Character* ccopy = l[i]->spawn_copy();
				copies.push_back(ccopy);
				std::cout << l[i]->get_name() << " Creates copy " << ccopy->get_name() << std::endl;
			}
			else if (rand() % 100 < 50)
			{
				Character* target = l[i]->attack(l);
				std::cout << l[i]->get_name() << " attacks " << target->get_name() << std::endl;
			}
		}
		for (int i{ 0 }; i < l.size(); ++i)
		{
			if (l[i]->get_hp() <= 0)
			{
				std::cout << l[i]->get_name() << " Has died..." << std::endl;
			}
			else
			{
				copies.push_back(l[i]);
			}
		}
		l = copies;
		for (Character* c : l) {
			dc->draw_character(c);
		}
	}

}