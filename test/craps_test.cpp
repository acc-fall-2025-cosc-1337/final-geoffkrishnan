#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
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

// Question 4 test cases

TEST_CASE("Test ComeOutPhase returns natural for 7 and 11") {
	Die x;
	Die y;
	Roll roll(x, y);
	ComeOutPhase come_out_phase;
	int point_values[] = {7, 11};

	for (int value : point_values) {
		roll.set_roll_value(value);
		REQUIRE(come_out_phase.get_outcome(&roll) == RollOutcome::natural);
	}
}

TEST_CASE("Test ComeOutPhase returns craps for 2, 3, and 12") {
	Die x;
	Die y;
	Roll roll(x, y);
	ComeOutPhase come_out_phase;
	int point_values[] = {2, 3, 12};

	for (int value : point_values) {
		roll.set_roll_value(value);
		REQUIRE(come_out_phase.get_outcome(&roll) == RollOutcome::craps);
	}
}

TEST_CASE("Test ComeOutPhase returns point for 4, 5, 6, 8, 9 and 10") {
	Die x;
	Die y;
	Roll roll(x, y);
	ComeOutPhase come_out_phase;
	int point_values[] = {4, 5, 6, 8, 9, 10};

	for (int value : point_values) {
		roll.set_roll_value(value);
		REQUIRE(come_out_phase.get_outcome(&roll) == RollOutcome::point);
	}
}

TEST_CASE("Test PointPhase returns point when roll == point") {
	Die x;
	Die y;
	Roll roll(x, y);
	
	PointPhase phase_4(4);
	roll.set_roll_value(4);
	REQUIRE(phase_4.get_outcome(&roll) == RollOutcome::point);
	
	PointPhase phase_6(6);
	roll.set_roll_value(6);
	REQUIRE(phase_6.get_outcome(&roll) == RollOutcome::point);
	
	PointPhase phase_10(10);
	roll.set_roll_value(10);
	REQUIRE(phase_10.get_outcome(&roll) == RollOutcome::point);
}

TEST_CASE("Test PointPhase returns seven_out when roll == 7") {
	Die x;
	Die y;
	Roll roll(x, y);
	
	PointPhase phase(6);
	roll.set_roll_value(7);
	REQUIRE(phase.get_outcome(&roll) == RollOutcome::seven_out);
}

TEST_CASE("Test PointPhase returns nopoint for remaining values") {
	Die x;
	Die y;
	Roll roll(x, y);
	
	PointPhase phase(6); 
	int nopoint_values[] = {2, 3, 4, 5, 8, 9, 10, 11, 12}; 
	
	for (int value : nopoint_values) {
		roll.set_roll_value(value);
		REQUIRE(phase.get_outcome(&roll) == RollOutcome::nopoint);
	}
}