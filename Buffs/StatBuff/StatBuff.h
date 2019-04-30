/*
 * StatBuff.h
 *
 *  Created on: 4 Mar 2019
 *      Author: PatrickC
 */

#ifndef STATBUFF_H_
#define STATBUFF_H_

#include "Buff.h"
#include <array>

using Stats = std::array<int, 11>;

class StatBuff: public Buff {
	Stats buffStats;

public:
	StatBuff(int t, Stats bs) :
			turns(t), buffStats(bs) {
	}

	Stats getBuffStats() {
		return buffStats;
	}
};

#endif /* STATBUFF_H_ */
