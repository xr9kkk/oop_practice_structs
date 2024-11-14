#pragma once
#include <string>
#include "Coordinates.h"
#include <vector>

class Character {
private:
    std::string name;
    Coordinates* coordinates;
    int level{};
    int hp{};
    const int spawn_radius{ 20 };
    int turns_alive{ 0 };
    Character* parent{ nullptr }; 

public:
    Character(std::string name, Coordinates* c, int level, int hp, Character* parent = nullptr)
        : name(name), coordinates(c), level(level), hp(hp), parent(parent) {}

    ~Character() { delete coordinates; }

    std::string get_name() const { return name; }
    Coordinates* get_coordinates() const { return coordinates; }
    int get_level() const { return level; }
    int get_hp() const { return hp; }
    void decrease_hp(int amount) { hp -= amount; }
    void increment_turns() { ++turns_alive; }
    int get_turns_alive() const { return turns_alive; }

    bool is_copy() const { return parent != nullptr; }
    bool is_dead() const { return hp <= 0; }

    Character* spawn_copy(); 
    Character* attack(std::vector<Character*>& list);
    Character* get_parent() const { return parent; } 
};
