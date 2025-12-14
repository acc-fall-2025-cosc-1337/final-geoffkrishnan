#ifndef SHOOTER_H 
#define SHOOTER_H
#include "roll.h"
#include <vector>

class Shooter
{
public:
    Roll* throw_dice(Die& x, Die& y);
    void display_rolled_values();
    ~Shooter();

private:
    std::vector<Roll*> rolls{};
};

#endif