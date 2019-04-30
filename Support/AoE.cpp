/*
 * AoE.cpp
 *
 *  Created on: 19 Jan 2019
 *      Author: PatrickC
 */

#include <array>
#include <vector>
#include <iostream>
#include <cmath>
#include "Map.h"

using Position = std::array<int, 2>;

std::vector<Position> AoE(Position startingPosition, int size, bool showAoE =
		false) {
	std::vector<Position> effectedPositions;

	effectedPositions.push_back(startingPosition);

	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (abs(i + j) <= size + ceil(size / 3.0) && abs(i + j) != 0) {
				effectedPositions.push_back(
						{ startingPosition[0] + i, startingPosition[1] + j });
				effectedPositions.push_back(
						{ startingPosition[0] - i, startingPosition[1] - j });
				if (abs(i + j) != 1 && i > 0 && j > 0) {
					effectedPositions.push_back(
							{ startingPosition[0] - i, startingPosition[1] + j });
					effectedPositions.push_back(
							{ startingPosition[0] + i, startingPosition[1] - j });
				}
			}
		}
	}

	for (int i = effectedPositions.size() - 1; i > 0; i--) {
		if (effectedPositions[i][0] > 16 || effectedPositions[i][0] < 0
				|| effectedPositions[i][1] > 16
				|| effectedPositions[i][1] < 0) {
			effectedPositions.erase(effectedPositions.begin() + i);
		}
	}

//	for(int i = 0; i < effectedPositions.size(); i++) {
//		for(int j = 0; i < 2; j++) {
//			std::cout << effectedPositions[i][j] << "-";
//		}
//		std::cout << std::endl;
//	}

	if (showAoE) {
		Map::displayAoE(effectedPositions);
	}

	return effectedPositions;

}

/*
 * Positions;
 * startingPos[0] + 1, startingPos[1]
 * startingPos[0] - 1, startingPos[1]
 *
 * startingPos[0], startingPos[1] + 1
 * startingPos[0], startingPos[1] - 1
 *
 * startingPos[0] + 1, startingPos[1] - 1
 * startingPos[0] - 1 , startingPos[1] + 1
 *
 * startingPos[0] + 1, startingPos[1] + 1
 * startingPos[0] - 1 , startingPos[1] - 1
 *
 *
 *
 *
 * startingPos[0] + 1, startingPos[1]
 * startingPos[0] + 2, startingPos[1]
 *
 * startingPos[0] + 1, startingPos[1] + 1
 * startingPos[0] + 2, startingPos[1] + 1
 *
 * startingPos[0] + 1, startingPos[1] + 2
 * startingPos[0] + 2, startingPos[1] + 2
 *
 */
