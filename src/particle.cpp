/*
 * particle.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: user
 */
#include "../headers/particle.h"
#include <math.h>

int Particle::updatePosition(float dt) {
	/* First update has to set up half step velocities */
	if (!has_started) {
		/* Initialize half-step velocity */
		vh[0] = v[0] + a[0]*dt/2;
		vh[1] = v[1] + a[1]*dt/2;
		/* Initialize velocity */
		v[0] += a[0]*dt;
		v[1] += a[1]*dt;
		/* Initialize position */
		x[0] += vh[0]*dt;
		x[1] += vh[1]*dt;

		has_started = 1;
	}
	else
	{
		/* Update half-step velocity */
		vh[0] += a[0]*dt;
		vh[1] += a[1]*dt;
		/* Update velocity */
		v[0] = vh[0] + a[0]*dt/2;
		v[1] = vh[1] + a[1]*dt/2;
		/* Update positions */
		x[0] += vh[0]*dt;
		x[1] += vh[1]*dt;
	}

	return 1;
}

float Particle::getPressure() {
	return k * pow(rho,1 + 1/n);
}




