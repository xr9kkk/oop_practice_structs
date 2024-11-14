#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "Character.h"
#include "DrawController.h"

int main() {
    using namespace std::chrono_literals;
    srand(time(NULL));

    std::vector<Character*> list;
    list.push_back(new Character("Sasha", new Coordinates(0, 0), 10, 5));
    list.push_back(new Character("Alexandr", new Coordinates(10, 0), 20, 10));
    list.push_back(new Character("Sanya", new Coordinates(50, 20), 10, 5));
    list.push_back(new Character("Olesya", new Coordinates(100, -20), 5, 20));
    list.push_back(new Character("Kirill", new Coordinates(100, -20), 20, 9));

    DrawController* dc = new DrawController();

    for (Character* c : list) {
        dc->draw_character(c);
    }

    while (true) {
        std::vector<Character*> next_round;
        int alive_count = 0;
        for (int i = 0; i < list.size(); ++i) {
            list[i]->increment_turns();
            if (list[i]->get_hp() > 0) {
                alive_count++;
            }

            if (rand() % 100 < 25) {
                Character* copy = list[i]->spawn_copy();
                next_round.push_back(copy);
                std::cout << list[i]->get_name() << " creates copy " << copy->get_name() << std::endl;
            }
            else if (rand() % 100 < 50) {
                Character* target = list[i]->attack(list);
                std::cout << list[i]->get_name() << " attacks " << target->get_name() << std::endl;
            }
        }

        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->is_dead()) {
                std::cout << list[i]->get_name() << " has died..." << std::endl;
            }
            else {
                if (list[i]->is_copy() && list[i]->get_turns_alive() > 2) {
                    std::cout << list[i]->get_name() << " copy has lived for 2 turns and dies..." << std::endl;
                }
                else {
                    next_round.push_back(list[i]);
                }
            }
        }

        list = next_round;

        for (Character* c : list) {
            dc->draw_character(c);
        }

        if (alive_count <= 1) {
            std::cout << "Only one character is left alive!" << std::endl;

            // Вывод информации о выжившем персонаже
            for (Character* c : list) {
                if (!c->is_dead()) {
                    std::cout << "The winner is: " << c->get_name() << std::endl;
                    std::cout << "Level: " << c->get_level() << ", HP: " << c->get_hp() << std::endl;
                    std::cout << "Coordinates: (" << c->get_coordinates()->get_x() << ", " << c->get_coordinates()->get_y() << ")\n";
                }
            }

            break;
        }

        std::this_thread::sleep_for(100ms);
    }

    // Очистка памяти
    for (Character* c : list) {
        delete c;
    }
    delete dc;

    return 0;
}
