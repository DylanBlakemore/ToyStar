//============================================================================
// Name        : ToyStar.cpp
// Author      : Dylan Blakemore
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "../headers/particle.h"
#include "../headers/solver.h"

using namespace std;

vector<Particle> generateParticles() {
	return 0;
}

int main() {
	int n_steps = 50;

	vector<Particle> particles = generateParticles();
	ParticleSolver solver(particles);

	for (int step = 0; step < n_steps; step++)
	{
		solver.update();
	}

	return 0;
}
