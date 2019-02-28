#include "Crafts.h"
#include "Dice.h"

//0 = Target
//1 = Set
//2 = line
//3 = self
//4 = allies
//5 = self/allies
//6 = set/allies

void Craft::displayCraftDescription() {
	std::cout << "\nCP cost: " << craftPoints << "\tArea of Effect radius: " << AoESize << "\tTargetting type: ";
	if(targetting == 0) {
		std::cout << "Target/Enemies";
	} else if(targetting == 1) {
		std::cout << "Set";
	} else if(targetting == 2) {
		std::cout << "Line";
	} else if(targetting == 3) {
		std::cout << "Self/Enemies";
	} else if(targetting == 4) {
		std::cout << "Target/Allies";
	} else if(targetting == 5) {
		std::cout << "Self/Allies";
	} else if(targetting == 6) {
		std::cout << "Set/Allies";
	} else if(targetting == 7) {
		std::cout << "All";
	}
	std::cout << std::endl;



	displaySpecificCraftDescription();
}
