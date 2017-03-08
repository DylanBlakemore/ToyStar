/*
 * particle.h
 *
 *  Created on: Mar 7, 2017
 *      Author: user
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle {
public:
	Particle();

	void updatePosition();

	float x[2];
	float v[2];
	float v_half[2];
	float rho;
};



#endif /* PARTICLE_H_ */
