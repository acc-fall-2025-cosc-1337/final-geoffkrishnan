#ifndef ROLL_H 
#define ROLL_H
#include "die.h"

class Roll
{
public:
    Roll(Die& die_a, Die& die_b);
    void roll_dice();
    int roll_value() const { return rolled_values; };


private:
    Die& die1;
    Die& die2;
    int rolled_values{0};
};

#endif