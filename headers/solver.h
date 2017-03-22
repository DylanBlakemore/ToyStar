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
		t = 0;
		iter = 0;

		for (int i = 0; i < N; i++)
		{
			setParticleLambda(particles[i]);
		}

	}

	void update(Kernel* kernel, float dt);

	vector<vector<float> > getHistory(){return history;}

private:
	void calculateDensities(Kernel* kernel);
	void calculateAccelerations(Kernel* kernel);
	void setParticleLambda(Particle& p);

	float M;	// total mass
	float R;	// star radius
	float N;	// number of particles
	float nu;	// damping constant
	float t;	// time
	float iter;
	vector<Particle> particles;
	vector<vector<float> > history;
};



#endif /* SOLVER_H_ */
