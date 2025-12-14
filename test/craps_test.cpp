#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include <ctime>


//Question 1 test case
TEST_CASE("Test die roll returns value from 1 to 6") {
	srand(time(0));
	Die die;

	for(int i = 0; i < 10; i++) {
		int roll = die.roll();
		//seperate asserts for clearer debugging
		REQUIRE(roll >= 1);
		REQUIRE(roll <= 6);
	}
}

// Question 2 test case
TEST_CASE("Test dice rolls returns value from 2 to 12") {
	srand(time(0));
	Die x;
	Die y;
	Roll roll(x, y) ;
	for(int i = 0; i < 10; i++) {
		roll.roll_dice();
		REQUIRE(roll.roll_value() >= 2);
		REQUIRE(roll.roll_value() <= 12);
	}
}

// Question 3 test case
TEST_CASE("Test Roll result returns value from 2 to 12") {
	srand(time(0));
	Die x;
	Die y;
	Shooter shooter;
	for(int i = 0; i < 10; i++) {
		Roll* roll = shooter.throw_dice(x, y);
		REQUIRE(roll->roll_value() >= 2);
		REQUIRE(roll->roll_value() <= 12);
	}
}
