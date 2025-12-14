#include "shooter.h"
#include <iostream>
Roll* Shooter::throw_dice(Die& x, Die& y) {
    Roll* roll_ptr = new Roll(x, y);
    roll_ptr->roll_dice();
    rolls.push_back(roll_ptr);
    return roll_ptr;
}

void Shooter::display_rolled_values() {
    for (auto& roll_ptr: rolls) {
        std::cout << roll_ptr->roll_value() << std::endl;
    }
}

Shooter::~Shooter() {
    for (auto roll_ptr: rolls) {
        delete roll_ptr;
    }
}