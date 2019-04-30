/*
 * sigmoid.cpp
 *
 *  Created on: 28 Mar 2019
 *      Author: PatrickC
 */
#include <cmath>

double sigmoid(double z) {
	return 1 / (1 + exp(-z));
}

