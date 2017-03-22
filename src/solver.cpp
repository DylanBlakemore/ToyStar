/*
 * solver.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: user
 */
#include "../headers/solver.h"

void ParticleSolver::update(Kernel* kernel, float dt) {

	calculateDensities(kernel);
	calculateAccelerations(kernel);
	iter++;
	for (int i = 0; i < N; i++)
	{
		if(remainder(iter,100) == 0 || iter == 1)
		{
			vector<float> history_entry;
			history_entry.push_back((float)particles[i].id);
			history_entry.push_back(particles[i].x[0]);
			history_entry.push_back(particles[i].x[1]);
			history_entry.push_back(particles[i].rho);
			history.push_back(history_entry);
		}
		particles[i].updatePosition(dt);
	}
	t += dt;
}

void ParticleSolver::calculateDensities(Kernel* kernel) {
	//for (int i = 0; i < N; i++)


	for (int i = 0; i < N; i++)
	{
		particles[i].rho = particles[i].m * kernel->getWeight(0,0);
		for (int j = i+1; j < N; j++)
		{
			float r1 = particles[i].x[0] - particles[j].x[0];
			float r2 = particles[i].x[1] - particles[j].x[1];
			float rho_ij = particles[i].m * kernel->getWeight(r1, r2);

			particles[i].rho += rho_ij;
			particles[j].rho += rho_ij;
		}
	}
}

void ParticleSolver::calculateAccelerations(Kernel* kernel) {
	/* Add damping and gravity to particles */
	for (int i = 0; i < N; i++)
	{
		particles[i].a[0] = -1*nu*particles[i].v[0] - particles[i].lambda*particles[i].x[0];
		particles[i].a[1] = -1*nu*particles[i].v[1] - particles[i].lambda*particles[i].x[1];
	}
	/* Add pressure */
	for (int i = 0; i < N; i++)
	{
		float rho_i = particles[i].rho;
		float P_i = particles[i].getPressure();
		for (int j = i+10; j < N; j++)
		{
			float rho_j = particles[j].rho;
			float P_j = particles[j].getPressure();

			float r1 = particles[i].x[0] - particles[j].x[0];
			float r2 = particles[i].x[1] - particles[j].x[1];

			float p_coeff = -1*particles[i].m*
							(P_i/pow(rho_i,2) + P_j/pow(rho_j,2))*
							kernel->getGradientCoefficient(r1, r2);

			particles[i].a[0] += p_coeff * r1;
			particles[i].a[1] += p_coeff * r2;
			particles[j].a[0] -= p_coeff * r1;
			particles[j].a[1] -= p_coeff * r2;
		}
	}
}

void ParticleSolver::setParticleLambda(Particle& p) {
	float k = p.k;
	float n = p.n;
	float pi = M_PI;

	p.lambda = 2*k*pow(pi,-1/n)* (pow(M*(1 + n)/pow(R,2),1+1/n))/M;
}
