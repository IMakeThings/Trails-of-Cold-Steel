/*
 * convertPos1t1ons.cpp
 *
 *  Created on: 18 Jan 2019
 *      Author: Patr1ckC
 */


#include <string>
#include <iostream>
#include <array>



int convertPosition(std::string newPosition) {
    int pos = 0;

    if(newPosition.length() == 1) {
    	switch(newPosition[0]) {
			case '1': pos = 0;
				break;
			case '2': pos = 1;
				break;
			case '3': pos = 2;
				break;
			case '4': pos = 3;
				break;
			case '5': pos = 4;
				break;
			case '6': pos = 5;
				break;
			case '7': pos = 6;
				break;
			case '8': pos = 7;
				break;
			case '9': pos = 8;
				break;
			default: std::cout << "Please enter a number from 1 to 17 to represent spaces on the board" << std::endl;
				return -1;
				break;
    	}

		return pos;
    }


	switch(newPosition[0]) {
		case '1': pos = 10;
			break;
		default: std::cout << "Please enter a number from 1 to 17 to represent spaces on the board" << std::endl;
			return -1;
			break;
	}


	switch(newPosition[1]) {
		case '0' : pos += -1;
			break;
		case '1': pos += 0;
			break;
		case '2': pos += 1;
			break;
		case '3': pos += 2;
			break;
		case '4': pos += 3;
			break;
		case '5': pos += 4;
			break;
		case '6': pos += 5;
			break;
		case '7': pos += 6;
			break;
		default: std::cout << "Please enter a number from 1 to 17 to represent spaces on the board" << std::endl;
		return -1;
			break;

    }
    return pos;
}
