#include "Character.h"
#include <iostream>
#include <algorithm>
#include "Dice.h"
extern int convertPosition(std::string newPosition);
extern Position inputPositions();
extern Entity* inputSelectEntity(int which = 0);
extern std::vector<Position> AoE(Position startingPosition, int size,
		bool showAoE = false);
extern void enterPause();
extern void consoleMenu();
#include "PlayerAI.h"

// UPDATES ---------------------------------------------------------------------------------------------
void Character::updateArts_MasterQuartz() {
	bool added = false;
	for (int i = 0; i < (signed) getMasterQuartz()->getArts().size(); i++) {
		for (int j = 0; j < (signed) getArts().size(); j++) {
			if (getMasterQuartz()->getArts()[i]->getName()
					== getArts()[j]->getName()) {
				added = true;
			}
		}
		if (!added) {
			addArt(getMasterQuartz()->getArts()[i]);
		}
		added = false;
	}
}

void Character::updateStats_Equipment() {
	Stats updateStats = getTotalStats();
	for (int i = 0; i < (signed) getTotalStats().size(); i++) {
		updateStats[i] += getEquipment().back()->getStatsModifier()[i];
	}
	setTotalStats(updateStats);
}

void Character::updateStats_MasterQuartz() {
	Stats updateStats = getTotalStats();
	for (int i = 0; i < (signed) getTotalStats().size(); i++) {
		updateStats[i] += getMasterQuartz()->getStatsModifier()[i];
	}
	setTotalStats(updateStats);
}

void Character::updateStats_Quartz() {
	Stats updateStats = getTotalStats();
	for (int i = 0; i < (signed) getTotalStats().size(); i++) {
		updateStats[i] += getQuartz().back()->getStatsModifier()[i];
	}
	setTotalStats(updateStats);
}
// END -----------------------------------------------------------------------------------------------

// USE CRAFT FNCS -------------------------------------------------------------------------------------------
void Character::useCraft(Craft* usedCraft) {
	Position tar;
	Entity* ene;
	if (usedCraft->getTargetting() == 0) {
		ene = inputSelectEntity();
		if (ene == NULL) {
			takeTurn();
			return;
		}
		tar = ene->getPositions();
	} else if (usedCraft->getTargetting() == 1
			|| usedCraft->getTargetting() == 2) {
		tar = inputPositions();
	} else if (usedCraft->getTargetting() == 3) {
		tar = getPositions();
	} else if (usedCraft->getTargetting() == 4) {
		tar = inputSelectEntity(1)->getPositions();
	} else if (usedCraft->getTargetting() == 5) {
		tar = getPositions();
	} else if (usedCraft->getTargetting() == 6) {
		tar = inputPositions();
	}

	std::vector<Position> range = AoE(tar, getRNG());

	if (getDistanceToPoint(tar) <= getRNG()) {

	} else if (getDistanceToPoint(findClosestPositionToPointInRange(tar))
			<= getMOV()) {
		moveAttack(usedCraft, tar);

		Map::update();

	} else {
		std::string cool;
		std::cout << "This tile is out of your range\nPress enter to continue.";
		getline(std::cin, cool);
		takeTurn();
		return;
	}

	//Checks if you have enough CP
	if (getCP() < usedCraft->getCraftPoints()) {
		std::cout << "You do not have enough craft points.\n";
		takeTurn();
		return;
	}

	std::vector<Position> effected = AoE(getPositions(), getTotalStats()[10]);

	setCP(getCP() - usedCraft->getCraftPoints());

	effected = AoE(tar, usedCraft->getAoESize(), true);
	//std::cout << effected.size();

	usedCraft->craftAimedFunctions(this, tar);

	std::vector<Entity*> appliedTo;

	if (usedCraft->getTargetting() == 4 || usedCraft->getTargetting() == 5
			|| usedCraft->getTargetting() == 6) {
		appliedTo = Entity::getCharacters();
	} else {
		appliedTo = Entity::getEnemies();
	}

	//For every enemy in the same position as the effected, apply damage to them.
	for (int i = 0; i < (signed) appliedTo.size(); i++) {
		for (int j = 0; j < (signed) effected.size(); j++) {
			if ((appliedTo[i]->getPositions()[0]) == effected[j][0]
					&& (appliedTo[i]->getPositions()[1]) == effected[j][1]) {
				if (usedCraft->getAoESize() > 0) {
					setCP(getCP() + 3);
				} else {
					setCP(getCP() + 10);
				}
				useCraft(usedCraft, appliedTo[i]);
			}
		}
	}
	if (usedCraft->displayAfterHitDescription(this)) {
		enterPause();
	}
}

void Character::useCraft(Craft* usedCraft, Entity* enemy, bool followUpAttack) {

	std::string cool;

	int damageDealt = getAttackModifier() + usedCraft->getBaseDamage();

	if (!isCharacter(enemy) && !followUpAttack) {
		if (getPhysicalModifier(enemy) >= 0) {
			damageDealt += getPhysicalModifier(enemy);
		} else {
			damageDealt *= 0.5;
		}
	}

	if (!isCharacter(enemy) && !isHit(enemy)) {
		std::cout << "You missed!\n\n";
		enemy->useCraft(getBasicAttack(), this, false);
		return;
	}

	if (isCharacter(enemy)) {
		damageDealt = 0;
	}

	usedCraft->craftOnHitFunctions(enemy);

	enemy->setHP(enemy->getHP() - damageDealt);
	usedCraft->displayHitDescription(this, enemy, damageDealt);

	if (isUnbalanced(enemy, usedCraft) && !followUpAttack
			&& !isCharacter(enemy)) {
		std::cout << "\nYou have unbalanced " << enemy->getName()
				<< ". Your link gets to attack!\n\n";
		link->useCraft(getBasicAttack(), enemy, true);
		return;
	}
	enterPause();
}

// END ------------------------------------------------------------------------------------------------

// USE ART FNCS --------------------------------------------------------------------------------------
void Character::useArt(Art* usedArt) {
	if (getCastingArt() == NULL) {

		if (getEP() < usedArt->getEPCost()) {
			std::cout << "You do not have enough EP to cast "
					<< usedArt->getName() << std::endl;
			takeTurn();
			return;
		}

		Position tar;
		Entity* ene;
		if (usedArt->getTargetting() == 0) {
			ene = inputSelectEntity();
		} else if (usedArt->getTargetting() == 1
				|| usedArt->getTargetting() == 2) {
			tar = inputPositions();
		} else if (usedArt->getTargetting() == 3) {
			ene = this;
		} else if (usedArt->getTargetting() == 4) {
			ene = inputSelectEntity(1);
		} else if (usedArt->getTargetting() == 5) {
			ene = this;
		} else if (usedArt->getTargetting() == 6) {
			tar = inputPositions();
		}

		if (ene == NULL) {
			takeTurn();
			return;
		}

		if (ene != NULL) {
			usedArt->setCasting(ene);
			std::cout << "You have started casting " << usedArt->getName()
					<< ", targetting " << ene->getName() << std::endl;
		} else {
			usedArt->setCasting(tar);
			std::cout << "You have started casting " << usedArt->getName()
					<< ", at the position " << tar[0] + 1 << "-" << tar[1] + 1
					<< std::endl;
		}
		setCastingArt(usedArt);

		std::cout << "\n" << usedArt->getName() << " takes "
				<< usedArt->getCastTime() << " Action Ticks to cast.\n\n";
		enterPause();
		return;
	}

	setCP(getCP() - usedArt->getEPCost());

	std::vector<Position> effected = AoE(usedArt->getAimedPosition(),
			usedArt->getAoESize());

	std::cout << "You have casted " << usedArt->getName() << " at "
			<< usedArt->getAimedPosition()[0] + 1 << "-"
			<< usedArt->getAimedPosition()[1] + 1 << std::endl;
	enterPause();

	for (int i = 0; i < (signed) getEntities().size(); i++) {
		for (int j = 0; j < (signed) effected.size(); j++) {
			if (getEntities()[i]->getPositions()[0] == effected[j][0]
					&& getEntities()[i]->getPositions()[1] == effected[j][1]) {
				useArt(usedArt, getEntities()[i]);
			}
		}
	}
	setCastingArt(NULL);

}

void Character::useArt(Art* usedArt, Entity* enemy) {

	int damageDealt = getArtDamage(usedArt);
	if (getMagicModifier(enemy) >= 0) {
		damageDealt += getMagicModifier(enemy);
	} else {
		damageDealt *= 0.5;
	}
	enemy->setHP(enemy->getHP() - damageDealt);
	std::cout << getName() << " dealt " << damageDealt << " Damage!\n\n";
	std::cout << enemy->getName() << " has " << enemy->getHP()
			<< " health remaining!\n\n";
	enterPause();
}

int Character::getArtDamage(Art* art) {
	return art->getBaseDamage() + getArtModifier();
}

// END -----------------------------------------------------------------------------------------------------

bool Character::isCharacter(Entity* entity) {
	for (int i = 0; i < (signed) Entity::getCharacters().size(); i++) {
		if (entity == Entity::getCharacters()[i]) {
			return (true);
		}
	}
	return (false);
}

//CHARACTER TURNS ---------------------------------------------------------------------------------------
void Character::takeTurn() {
	counter++;
	if (counter >= 50) {
		return;
	}
	std::cout
			<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Map::update();
	Map::display();
	std::string input;
	std::string target;

	if (getCastingArt() != NULL) {
		std::cout << "You are still casting " << getCastingArt()->getName();
		AoE(getCastingArt()->getAimedPosition(), true);
		enterPause();
		return;
	}

	std::cout << getName() << "'s turn.\n\nYour current stats are:\n"
			<< std::endl;

	std::string stattypes[11] = { "HP", "EP", "STR", "DEF", "ATS", "ADF", "SPD",
			"DEX", "AGL", "MOV", "RNG" };
	for (int i = 0; i < 11; i += 1) {
		if (i < 2) {
			std::cout << stattypes[i] << "    " << getTotalStats()[i]
					<< std::endl;
		} else if (i == 2) {
			std::cout << "CP    " << getCP() << std::endl;
			std::cout << stattypes[i] << "   " << getTotalStats()[i]
					<< std::endl;
		} else {
			std::cout << stattypes[i] << "   " << getTotalStats()[i]
					<< std::endl;
		}
	}
	std::cout << "ACT   " << getActionTicks() << std::endl;
	std::cout << "POS   " << getPositions()[0] << "-" << getPositions()[1]
			<< std::endl;
	std::cout << "Link: " << link->getName();
	std::cout << "\n\n";

	std::cout << "(1) Crafts		(2) Arts		(3) Attack\n(4) Move		(5) Link"
			<< std::endl;

//	std::vector<double> X;
//	X.push_back(getHP());
//	X.push_back(getPositions()[0]);
//	X.push_back(getPositions()[1]);

//	std::cout << X.size() << std::endl;
//
//	input = AI->runNet(X);
//	X.clear();

	getline(std::cin, input);

	if (input == "1") {
		takeTurn_Craft();
	} else if (input == "2") {
		takeTurn_Art();
	} else if (input == "3") {
		useCraft(getBasicAttack());
	} else if (input == "4") {
		move();
	} else if (input == "5") {
		takeTurn_Link();
	} else if (input == "6") {
		consoleMenu();
		takeTurn();
		return;
	} else {
		takeTurn();
		return;
	}
	counter = 0;
}

void Character::takeTurn_Craft() {
	std::string input;
	std::string target;

	std::cout << "You can currently attack the marked squares.\n";

	showCurrentRange();

	std::cout << std::endl;

	std::cout << "Select a Craft by typing its name or selecting its number:"
			<< std::endl;

	std::cout << std::endl;
	for (int i = 0; i < (signed) getCrafts().size(); i++) {
		std::cout << "(" << i + 1 << ")\t" << getCrafts()[i]->getName()
				<< std::endl;
		getCrafts()[i]->displayCraftDescription();
		std::cout << "\n\n\n";
	}
	std::cout << std::endl;

	//std::vector<double> X;
//	X.push_back(getHP());
//	X.push_back(getPositions()[0]);
//	X.push_back(getPositions()[1]);
//
//	std::cout << X.size() << std::endl;
//
//	input = AI->runNet(X);
//	X.clear();
	getline(std::cin, input);

	if (input == "") {
		takeTurn();
		return;
	}

	if (findCraft(input) == NULL) {
		std::cout << "This is not a valid craft\nPress enter to continue.\n"
				<< std::endl;
		getline(std::cin, input);
		takeTurn();
		return;
	}

	useCraft(findCraft(input));
}

void Character::takeTurn_Art() {
	std::string input;
	std::string target;
	Position tar;

	std::cout << "Select an Art by typing its name or selecting its number:"
			<< std::endl;

	std::cout << std::endl;
	for (int i = 0; i < (signed) getArts().size(); i++) {
		std::cout << "(" << i + 1 << ")\t" << getArts()[i]->getName()
				<< std::endl;
	}

	std::cout << std::endl;

//	std::vector<double> X;
//	X.push_back(getHP());
//	X.push_back(getPositions()[0]);
//	X.push_back(getPositions()[1]);
//
//	std::cout << X.size() << std::endl;
//
//	input = AI->runNet(X);
//	X.clear();
	getline(std::cin, input);

	if (input == "") {
		takeTurn();
		return;
	}

	if (findArt(input) == NULL) {
		std::cout << "\nThis is not a valid Art" << std::endl;
		takeTurn();
		return;
	}

	useArt(findArt(input));
}

void Character::takeTurn_BasicAttack() {
	useCraft(getBasicAttack());
}

void Character::move() {
	Position pos;
	std::string input;

	std::cout << "\n\nYour current position is: X = " << getPositions()[0] + 1
			<< ", Y = " << getPositions()[1] + 1;

	pos = inputPositions();

	moveEntity(pos);

	Map::update();
	Map::display();
	enterPause();
}

void Character::takeTurn_Link() {
	std::string input;

	std::cout << "You are currently linked to " << getLink()->getName()
			<< std::endl;

	std::cout << "\n\n(1) Choose new link		(2) Keep same link\n";

//	std::vector<double> X;
//	X.push_back(getHP());
//	X.push_back(getPositions()[0]);
//	X.push_back(getPositions()[1]);
//
//	std::cout << X.size() << std::endl;
//
//	input = AI->runNet(X);
//	X.clear();
	getline(std::cin, input);

	if (input == "") {
		takeTurn();
		return;
	}

	if (input == "2") {
		takeTurn();
		return;
	} else if (input == "1") {
		std::cout << "Please select a new character to link with:\n";
		for (int i = 0; i < (signed) getCharacters().size(); i++) {
			if (getCharacters()[i] != this) {
				std::cout << "(" << i + 1 << ") "
						<< getCharacters()[i]->getName() << std::endl;
			}
		}
	}
	//std::vector<double> X;
//	X.push_back(getHP());
//	X.push_back(getPositions()[0]);
//	X.push_back(getPositions()[1]);
//
//	std::cout << X.size() << std::endl;
//
//	input = AI->runNet(X);
//	X.clear();
	getline(std::cin, input);
	if (input == "") {
		takeTurn();
		return;
	}

	int index = convertPosition(input);

	setLink(getCharacters()[index]);

	takeTurn();
	return;
}
//END ------------------------------------------------------------------------------------------------------------

void Character::moveAttack(Craft* usedCraft, Position pos) {

	std::vector<Position> attackPoints = AoE(pos, getRNG());

	for (int i = 0; i < (signed) attackPoints.size(); i++) {
		for (int j = 0; j < (signed) getEntities().size(); j++) {
			if (attackPoints[i][0] == getEntities()[j]->getPositions()[0]
					&& attackPoints[i][1]
							== getEntities()[j]->getPositions()[1]) {
				attackPoints.erase(attackPoints.begin() + i);
			}
		}
	}
	if (attackPoints.size() == 0) {
		std::cout << "There is no space for you to attack this position.\n\n";
		takeTurn();
		return;
	}

	Position index = findClosestPositionOfAttackPoints(attackPoints);

	std::string moveAttack;

	AoE(index, 0, true);
	std::cout << "If you move, you can still use " << usedCraft->getName()
			<< std::endl;
	std::cout << "Would you like to do this?\n(1) Yes	(2) No\n\n";
	std::cout << "You will be moved to the marked position above.\n";

//	std::vector<double> X;
//	X.push_back(getHP());
//	X.push_back(getPositions()[0]);
//	X.push_back(getPositions()[1]);
//
//	std::cout << X.size() << std::endl;
//
//	moveAttack = AI->runNet(X);
//	X.clear();
	getline(std::cin, moveAttack);
	if (moveAttack == "2") {
		takeTurn();
	} else if (moveAttack == "1") {
		moveEntity(index);
	} else {
		takeTurn();
		return;
	}
}

void Character::showCurrentRange() {
	AoE(getPositions(), getRNG(), true);
}

bool Character::isUnbalanced(Entity* enemy, Craft* usedCraft) {
	float unbalanceChance = ranks[0] * enemy->getUnbalanceEfficacy()[0];

	for (int i = 1; i < (signed) ranks.size(); i++) {
		if (ranks[i] * enemy->getUnbalanceEfficacy()[i] > unbalanceChance) {
			unbalanceChance = ranks[i] * enemy->getUnbalanceEfficacy()[i];
		}
	}

	if (Dice::rollDx(1, 100, 0) < unbalanceChance + usedCraft->getUnbalance()) {
		return (true);
	}
	return (false);
}

