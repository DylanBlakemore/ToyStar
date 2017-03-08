/*
 * solver.h
 *
 *  Created on: Mar 7, 2017
 *      Author: user
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <vector>

#include "particle.h"
#include "kernel.h"

using namespace std;

class ParticleSolver {
public:
	ParticleSolver(vector<Particle>& particles);

	void update();

private:
	void initDensities();

};



#endif /* SOLVER_H_ */
