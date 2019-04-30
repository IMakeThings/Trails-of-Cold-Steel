/*
 * Tachi.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */
#include "Tachi.h"
#include "Dice.h"

const Stats Tachi::baseStats = { 15, 110, 12, 6, 3, 6, 8, 22, 17, 7, 1 };
const AttackRanks Tachi::ranks = { 25, 0, 0, 0 };
const std::string Tachi::representation = "T";
int Tachi::count = 0;

Tachi::Tachi(std::string n, Position position) :
		Character(baseStats, n, position, ranks, representation) {
	Tachi::count++;

	if (count > 9) {
		count = 1;
	}

	addCraft(new AutumnLeafCutter());
	addCraft(new Motivate());
	setName(getName() + " " + std::to_string(count));
	setRepresentation(getRepresentation() + std::to_string(count));
}

Tachi::Tachi(std::string n, Position position, PlayerAI* p) :
		Character(baseStats, n, position, ranks, representation, p) {
	Tachi::count++;

	if (count > 9) {
		count = 1;
	}

	addCraft(new AutumnLeafCutter());
	addCraft(new Motivate());
	setName(getName() + " " + std::to_string(count));
	setRepresentation(getRepresentation() + std::to_string(count));
}

int Tachi::getAttackModifier() {
	return Dice::rollDx(2, 6, 0);
}

int Tachi::getArtModifier() {
	return Dice::rollDx(1, 6, 0);
}

