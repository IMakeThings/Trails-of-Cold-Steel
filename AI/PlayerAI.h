/*
 * PlayerAI.h
 *
 *  Created on: 27 Mar 2019
 *      Author: PatrickC
 */

#ifndef PLAYERAI_H_
#define PLAYERAI_H_

#include <string>
#include <vector>

class PlayerAI {
	std::vector<std::vector<double>> Theta1;
	std::vector<std::vector<double>> Theta2;

	int cost;

public:
	//Any initialization like this gives Theta1 and Theta2 completely random inputs. Should only occur for generation 1.
	PlayerAI();
	PlayerAI(PlayerAI* parent1, PlayerAI* parent2);

	std::vector<std::vector<double>> getTheta1() {
		return Theta1;
	}
	std::vector<std::vector<double>> getTheta2() {
		return Theta2;
	}

	//Runs through a 1 hidden layer neural net
	std::string runNet(std::vector<double> X);

	// Converts output to the proper form.
	std::string convertOutput(std::vector<double> out);

	// Computes cost at the end of a turn
	void computeCost();
	int getCost() {
		return cost;
	}
	void setCost(int c) {
		cost = c;
	}

};

#endif /* PLAYERAI_H_ */
