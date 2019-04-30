#include "Dice.h"
#include <cstdlib>

int Dice::rollDx(int multiplier, int die, int modifier) {
	int roll = 0;
	for (int i = 0; i < multiplier; i++) {
		roll += rand() % die + 1;
	}
	return roll + modifier;
}
