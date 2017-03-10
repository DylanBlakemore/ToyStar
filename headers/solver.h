/*
 * solver.h
 *
 *  Created on: Mar 7, 2017
 *      Author: user
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <vector>
#include <math.h>

#include "particle.h"
#include "kernel.h"

using namespace std;

class ParticleSolver {
public:
	ParticleSolver(vector<Particle>& particles_in, float M_in, float R_in, float nu_in) {
		particles = particles_in;
		M = M_in;
		R = R_in;
		N = particles.size();
		nu = nu_in;

		for (int i = 0; i < N; i++)
		{
			setParticleLambda(particles[i]);
		}

	}

	void update(Kernel* kernel, float dt);

private:
	void calculateDensities(Kernel* kernel);
	void calculateAccelerations(Kernel* kernel);
	void setParticleLambda(Particle& p);

	float M;	// total mass
	float R;	// star radius
	float N;	// number of particles
	float nu;	// damping constant
	vector<Particle> particles;
};



#endif /* SOLVER_H_ */
