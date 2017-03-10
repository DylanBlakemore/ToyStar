//============================================================================
// Name        : ToyStar.cpp
// Author      : Dylan Blakemore
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>

#include "../headers/particle.h"
#include "../headers/solver.h"
#include "../headers/kernel.h"
#include "../headers/cubic_kernel.h"

using namespace std;

vector<Particle> generateParticles(int N, float m) {
	vector<Particle> particles;
	for (int i = 0; i < N; i++)
	{
		particles.push_back(Particle(position,m,i));
	}
	return particles;
}

int main() {
	int n_steps = 400;
	int N = 1;
	float h = 0.4/sqrt(N/1000);
	float M = 2;
	float R = 0.75;
	float nu = 1;
	float dt = 0.04;
	vector<Particle> particles = generateParticles(N, float(M)/float(N));
	CubicSplineKernel2D cubic = CubicSplineKernel2D(h);

	ParticleSolver solver(particles, M, R, nu);

	for (int step = 0; step < n_steps; step++)
	{
		solver.update(&cubic, dt);
	}

	return 0;
}
