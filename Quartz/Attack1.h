/*
 * Attack1.h
 *
 *  Created on: 18 Feb 2019
 *      Author: PatrickC
 */

#ifndef ATTACK1_H_
#define ATTACK1_H_

#include "Quartz.h"


class Attack1: public Quartz {
    static const Stats stats;
    static const std::string name;


public:
	 Attack1():Quartz(stats, name) {}
};



#endif /* ATTACK1_H_ */
