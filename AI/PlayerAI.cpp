/*
 * PlayerAI.cpp
 *
 *  Created on: 27 Mar 2019
 *      Author: PatrickC
 */
#include "PlayerAI.h"
#include "Entity.h"
extern double sigmoid(double z);
#include <iostream>
#include <algorithm>

PlayerAI::PlayerAI() {
	std::vector<double> idk;
	for (int nodes = 0; nodes < 10; nodes++) {
		for (int inputs = 0; inputs < 10; inputs++) {
			idk.push_back((5.0 * rand() / RAND_MAX) - 2.5);
		}
		Theta1.push_back(idk);
		idk.clear();
	}

	for (int nodes = 0; nodes < 6; nodes++) {
		for (int inputs = 0; inputs < 10; inputs++) {
			idk.push_back((5.0 * rand() / RAND_MAX) - 2.5);
		}
		Theta2.push_back(idk);
		idk.clear();
	}
}

PlayerAI::PlayerAI(PlayerAI* parent1, PlayerAI* parent2) {
	if ((double) rand() / RAND_MAX < 0.05) {
		std::vector<double> idk;
		for (int nodes = 0; nodes < 10; nodes++) {
			for (int inputs = 0; inputs < 10; inputs++) {
				idk.push_back((5.0 * rand() / RAND_MAX) - 2.5);
			}
			Theta1.push_back(idk);
			idk.clear();
		}

		for (int nodes = 0; nodes < 6; nodes++) {
			for (int inputs = 0; inputs < 10; inputs++) {
				idk.push_back((5.0 * rand() / RAND_MAX) - 2.5);
			}
			Theta2.push_back(idk);
			idk.clear();
		}
		return;
	}
	std::vector<double> placeHolder;

	for (int i = 0; i < parent1->getTheta1().size(); i++) {
		for (int j = 0; j < parent1->getTheta1()[0].size(); j++) {
			placeHolder.push_back(
					(parent1->getTheta1()[i][j] + parent2->getTheta1()[i][j])
							/ 2.0);
		}
		Theta1.push_back(placeHolder);
		placeHolder.clear();
	}
	for (int i = 0; i < parent1->getTheta2().size(); i++) {
		for (int j = 0; j < parent1->getTheta1()[0].size(); j++) {
			placeHolder.push_back(
					(parent1->getTheta1()[i][j] + parent2->getTheta1()[i][j])
							/ 2.0);
		}
		Theta2.push_back(placeHolder);
		placeHolder.clear();
	}
}

// X is a 1xM (M is the amount of inputs), theta1 should be numNodes x 1
std::string PlayerAI::runNet(std::vector<double> X) {
	X.insert(X.begin(), 1);
	std::vector<double> a2;
	std::vector<double> out;
	double sum = 0;

	for (int j = 0; j < Theta1.size(); j++) {
		for (int i = 0; i < X.size(); i++) {
			sum += X[i] * Theta1[j][i];
		}
		a2.push_back(sigmoid(sum));
		sum = 0;
	}
	a2.insert(a2.begin(), 0);

	for (int j = 0; j < Theta2.size(); j++) {
		for (int i = 0; i < a2.size(); i++) {
			sum += a2[i] * Theta2[j][i];
		}
		out.push_back(sigmoid(sum));
		sum = 0;
	}

	return convertOutput(out);
}

std::string PlayerAI::convertOutput(std::vector<double> out) {
	int maxElementIndex = std::max_element(out.begin(), out.end())
			- out.begin();

	std::string trueOutput;

	switch (maxElementIndex) {
	case 0:
		trueOutput = "1";
		break;
	case 1:
		trueOutput = "2";
		break;
	case 2:
		trueOutput = "3";
		break;
	case 3:
		trueOutput = "4";
		break;
	case 4:
		trueOutput = "5";
		break;
	case 5:
		trueOutput = "5";
		break;
	}

	return trueOutput;
}

void PlayerAI::computeCost() {
	int sum = 0;
	for (int i = 0; i < Entity::getEnemies().size(); i++) {
		sum += Entity::getEnemies()[i]->getHP();
	}

	cost = sum;
}
