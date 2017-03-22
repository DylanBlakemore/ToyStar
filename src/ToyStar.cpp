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
#include <stdlib.h>
#include <time.h>

#include "../headers/particle.h"
#include "../headers/solver.h"
#include "../headers/kernel.h"
#include "../headers/cubic_kernel.h"
#include "../headers/csv.h"

using namespace std;

vector<Particle> generateParticles(int N, float R, float m) {
	vector<Particle> particles;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		float r = (float)rand()/((float)RAND_MAX+1.0) * (2*R) - R;
		float theta = (float)rand()/((float)RAND_MAX+1.0) * (2*M_PI);
		vector<float> position;
		position.push_back(r*cos(theta));
		position.push_back(r*sin(theta));
		particles.push_back(Particle(position,m,i));
	}
	cout << "Number of particles: " << particles.size() << endl;
	return particles;
}

int main() {
	int n_steps = 4000;
	int N = 1000;
	float h = 0.04/sqrt((float)N/1000.0);
	float M = 2;
	float R = 0.75;
	float nu = 1;
	float dt = 0.004;
	vector<Particle> particles = generateParticles(N, R, float(M)/float(N));
	CubicSplineKernel2D cubic = CubicSplineKernel2D(h);

	ParticleSolver solver(particles, M, R, nu);

	for (int step = 0; step < n_steps; step++)
	{
		solver.update(&cubic, dt);
	}
	CSVFile outfile("output.csv", ',');
	outfile.open('w');
	vector<vector<float> > history = solver.getHistory();
	cout << "Number of entries: " << history.size() << endl;
	outfile.write(&history);
	cout << "Simulation complete." << endl;
	return 0;
}
