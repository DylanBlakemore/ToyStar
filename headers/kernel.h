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
		cout << "In parent getWeight" << endl;
		return 0;
	}

	virtual vector<float> getGradient(float r1, float r2) {
		cout << "In parent getGradient" << endl;
		return 0;
	}

	virtual float getLaplacian(float r1, float r2) {
		cout << "In parent getLaplacian" << endl;
		return 0;
	}

	virtual ~Kernel(){}

protected:
	float h;
};



#endif /* KERNEL_H_ */
