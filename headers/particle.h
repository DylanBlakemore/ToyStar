/*
 * particle.h
 *
 *  Created on: Mar 7, 2017
 *      Author: user
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <vector>

using namespace std;

class Particle {
public:
	Particle(vector<float>& initial_position, float mass, int ID) {
		x[0] = initial_position[0];
		x[1] = initial_position[1];
		v[0] = 0;
		v[1] = 0;

		n = 1;
		k = 0.1;
		rho = 0;
		lambda = 0;
		m = mass;

		has_started = 0;
		id = ID;
	}

	float getPressure();

	int updatePosition(float dt);

	float x[2];
	float v[2];
	float vh[2];
	float a[2];
	float rho;
	float k; // constant used in pressure calculation
	float n; // polytropic index
	float m; // particle mass
	float lambda;
	float id;

private:
	bool has_started;
};



#endif /* PARTICLE_H_ */
