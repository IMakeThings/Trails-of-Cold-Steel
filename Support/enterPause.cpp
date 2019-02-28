/*
 * enterPause.cpp
 *
 *  Created on: 17 Feb 2019
 *      Author: PatrickC
 */
#include <iostream>

void enterPause() {
	std::string pause;

	std::cout << "\n\nPress enter to continue.";
	getline(std::cin, pause);
	std::cout << "\n\n";
}


