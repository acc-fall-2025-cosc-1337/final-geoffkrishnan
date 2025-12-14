#include "roll.h"

Roll::Roll(Die& die_a, Die& die_b) : die1(die_a), die2(die_b) {}


void Roll::roll_dice() {
    rolled_value = die1.roll() + die2.roll();
}

void Roll::set_roll_value(int value) {
    rolled_value = value;
}