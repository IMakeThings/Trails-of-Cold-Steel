/*
 * inputPositions.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#include <array>
#include <iostream>
extern int convertPosition(std::string newPosition);

using Position = std::array<int, 2>;

Position inputPositions() {
	std::string target;
	Position tar;

	std::cout << "\nPlease input the horizontal position\n";
	getline(std::cin, target);
	tar[0] = convertPosition(target);
	std::cout << "\nPlease input the vertical position\n";
	getline(std::cin, target);
	tar[1] = convertPosition(target);

	return tar;
}
