#ifndef ROLL_H 
#define ROLL_H
#include "die.h"

class Roll
{
public:
    Roll(Die& die_a, Die& die_b);
    void roll_dice();
    int roll_value() const { return rolled_value; };
    void set_roll_value(int value);


private:
    Die& die1;
    Die& die2;
    int rolled_value{0};
};

#endif