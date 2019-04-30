/*
 * GreatSword.cpp
 *
 *  Created on: 17 Feb 2019
 *      Author: PatrickC
 */

#include "Greatsword.h"
#include "Dice.h"

const Stats Greatsword::baseStats = { 15, 100, 15, 12, 3, 9, 4, 19, 15, 6, 2 };
const AttackRanks Greatsword::ranks = { 5, 5, 10, 10 };
const std::string Greatsword::representation = "G";
int Greatsword::count = 0;

Greatsword::Greatsword(std::string n, Position position) :
		Character(baseStats, n, position, ranks, representation) {
	Greatsword::count++;
	if (count > 9) {
		count = 1;
	}

	setName(getName() + " " + std::to_string(count));
	setRepresentation(getRepresentation() + std::to_string(count));
}

int Greatsword::getAttackModifier() {
	return Dice::rollDx(2, 8, 0);
}

int Greatsword::getArtModifier() {
	return Dice::rollDx(1, 4, 0);
}

