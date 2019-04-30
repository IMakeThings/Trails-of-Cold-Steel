/*
 * Map.cpp
 *
 *  Created on: 18 Jan 2019
 *      Author: PatrickC
 */

#include "Map.h"
#include <iostream>

//std::vector<Entity*> Map::Entitys;
_Map Map::map;

extern std::vector<Position> AoE(Position startingPosition, int size,
		bool showAoE = false);

//Map::Map() {
//	for(int i = 0; i < map.size(); i++) {
//		for(int j = 0; j < map.size(); j++) {
//			map[i][j] = " ";
//		}
//	}
//}

void Map::generate() {
	for (int i = 0; i < (signed) map.size(); i++) {
		for (int j = 0; j < (signed) map.size(); j++) {
			map[i][j] = "  ";
		}
	}
}

void Map::display() {
	std::cout << "  " << 1;
	for (int i = 1; i < (signed) map.size(); i++) {
		if (i < 9) {
			std::cout << "  " << i + 1;
		} else {
			std::cout << " " << i + 1;
		}
	}
	std::cout << std::endl;
	for (int j = 0; j < (signed) map.size() * 3; j++) {
		std::cout << "_";
	}
	std::cout << "_";
	std::cout << "\n";
	for (int i = 0; i < (signed) map.size(); i++) {
		for (int j = 0; j < (signed) map.size(); j++) {
			std::cout << "|" << map[j][i];
		}

		std::cout << "|";
		std::cout << "  " << i + 1;
		std::cout << std::endl;

		for (int j = 0; j < (signed) map.size() * 3; j++) {
			std::cout << "_";
		}

		std::cout << "_";

		std::cout << "\n";
	}
}

void Map::displayAoE(Craft* usedCraft, Position pos) {
	std::vector<Position> effected = AoE(pos, usedCraft->getAoESize());

	for (int i = 0; i < (signed) effected.size(); i++) {
		map[effected[i][0]][effected[i][1]] = "XX";
	}

	display();
	update();
}

void Map::displayAoE(std::vector<Position> positions) {
	std::string waste;

	for (int i = 0; i < (signed) positions.size(); i++) {
		map[positions[i][0]][positions[i][1]] = "XX";
	}

	for (int i = 0; i < (signed) Entity::getEntities().size(); i++) {
		map[Entity::getEntities()[i]->getPositions()[0]][Entity::getEntities()[i]->getPositions()[1]] =
				Entity::getEntities()[i]->getRepresentation();
	}

	display();
	std::cout << "Press enter to continue.\n\n";
	getline(std::cin, waste);
	update();

}

void Map::update() {
	for (int i = 0; i < (signed) map.size(); i++) {
		for (int j = 0; j < (signed) map.size(); j++) {
			map[i][j] = "  ";
		}
	}

	for (int i = 0; i < (signed) Entity::getEntities().size(); i++) {
		map[Entity::getEntities()[i]->getPositions()[0]][Entity::getEntities()[i]->getPositions()[1]] =
				Entity::getEntities()[i]->getRepresentation();
	}
}
