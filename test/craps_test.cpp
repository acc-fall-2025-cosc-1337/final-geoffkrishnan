#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include <ctime>

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
