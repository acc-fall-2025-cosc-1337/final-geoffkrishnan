//being explicit about what headers are directly being used
//i know including just phase is enough
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int main() 
{
	srand(time(0));
	Die die1;
	Die die2;
	Shooter shooter;
	Roll* roll = shooter.throw_dice(die1, die2);
	int rolled_value = roll->roll_value();

	ComeOutPhase come_out_phase;
	while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps) {
		cout << "Rolled: " << rolled_value << " Roll again\n";
		roll = shooter.throw_dice(die1, die2);
		rolled_value = roll->roll_value();
	}

	cout << "Start of Point Phase: " << rolled_value << endl;
	cout << "Roll until " << rolled_value << " or 7 is rolled.\n";
	int point = rolled_value;
	roll = shooter.throw_dice(die1, die2);
	rolled_value = roll->roll_value();

	PointPhase point_phase(point);
	while (point_phase.get_outcome(roll) == RollOutcome::notpoint) {
		cout << "Rolled: " << rolled_value << " Roll again\n";
		roll = shooter.throw_dice(die1, die2);
		rolled_value = roll->roll_value();
	}
	cout << "Rolled value: " << rolled_value << " End of point phase\n";

	shooter.display_rolled_values();

	return 0;
}