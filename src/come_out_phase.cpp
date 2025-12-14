#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    switch (roll->roll_value()) {
        case 7:
        case 11:
            return RollOutcome::natural;
        case 2:
        case 3:
        case 12:
            return RollOutcome::craps;
        default:
            return RollOutcome::point;
    }
}