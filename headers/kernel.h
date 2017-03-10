/*
 * kernel.h
 *
 *  Created on: Mar 7, 2017
 *      Author: user
 */

#ifndef KERNEL_H_
#define KERNEL_H_

#include <iostream>
#include <vector>

using namespace std;

class Kernel {
public:
	Kernel(float h_in) {
		h = h_in;
	}

	virtual float getWeight(float r1, float r2) {
		return 0;
	}

	virtual float getGradientCoefficient(float r1, float r2) {
		return 0;
	}

	virtual float getLaplacian(float r1, float r2) {
		return 0;
	}

	virtual ~Kernel(){}

protected:
	float h;
};



#endif /* KERNEL_H_ */
