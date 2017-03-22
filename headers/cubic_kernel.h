/*
 * cubic_kernel.h
 *
 *  Created on: Mar 7, 2017
 *      Author: user
 */

#ifndef CUBIC_KERNEL_H_
#define CUBIC_KERNEL_H_

#include <vector>
#include <math.h>
#include "kernel.h"

using namespace std;

class CubicSplineKernel2D : public Kernel {
public:
	CubicSplineKernel2D(float h_in) :Kernel(h_in) {
		Ch = 5.0 / (14.0 * M_PI * pow(h,2));
	}
	/* Returns the weighting value */
	virtual float getWeight(float r1, float r2) {
		float r = getDistance(r1, r2);
		float weight = 0;
		float q = r/h;

		if (q >= 2)
			weight = 0;
		else if (q >= 1)
			weight = pow(2 - q,3);
		else if (q >= 0 && q < 1)
			weight = pow(2 - q,3) - 4*pow(1 - q,3);
		return weight * Ch;
	}

	/* Returns the gradient of the weighting function as a vector */
	virtual float getGradientCoefficient(float r1, float r2) {
		float coeff = 0;
		float r = getDistance(r1, r2);

		if (r > 0)
		{
			float q = r/h;
			float u = 2 - q;
			float v = pow(r,2);
			float w = 1 - q;

			float df1 = -3*pow(u,2)*pow(h,-1)*pow(v,-1/2);
			float df2 = -3*pow(w,2)*pow(h,-1)*pow(v,-1/2);

			if (q >= 2)
				coeff = 0;
			else if (q >= 1)
				coeff = Ch * df1;
			else if (q >= 0 && q < 1)
				coeff = Ch * (df1 - 4*df2);
		}
		return coeff;
	}

	/* Returns the laplacian of the weighting function */
	virtual float getLaplacian(float r1, float r2) {
		float laplacian = 0;
		float r = getDistance(r1, r2);

		if (r > 0)
		{
			float q = r/h;
			float u = 2 - q;
			float v = pow(r,2);
			float w = 1 - q;

			float d2f1_dr12 = (-6*u*pow(r1,2)*pow(h,-2)*pow(v,-1)) +
							  (3*pow(u,2)*pow(r1,2)*pow(h,-1)*pow(v,-3/2)) +
							  (3*pow(u,2)*pow(h,-1)*pow(v,-1/2));

			float d2f1_dr22 = (-6*u*pow(r2,2)*pow(h,-2)*pow(v,-1)) +
							  (3*pow(u,2)*pow(r2,2)*pow(h,-1)*pow(v,-3/2)) +
							  (3*pow(u,2)*pow(h,-1)*pow(v,-1/2));

			float d2f2_dr12 = (2*pow(v,-1)*pow(r1,2)*pow(h,-2)) +
							  (2*w*pow(v,-3/2)*pow(r1,2)*pow(h,-1)) +
							  (2*w*pow(v,-1/2)*pow(h,-1));

			float d2f2_dr22 = (2*pow(v,-1)*pow(r2,2)*pow(h,-2)) +
							  (2*w*pow(v,-3/2)*pow(r2,2)*pow(h,-1)) +
							  (2*w*pow(v,-1/2)*pow(h,-1));

			if (q >= 2)
				laplacian = 0;
			else if (q >= 1)
				laplacian = d2f1_dr12 + d2f1_dr22;
			else if (q >= 0 && q < 1)
				laplacian = (d2f1_dr12 + d2f1_dr22) - 4*(d2f2_dr12 + d2f2_dr22);
		}
		return laplacian * Ch;
	}

private:
	/* Returns the Euclidean distance between two points */
	float getDistance(float r1, float r2) {
		return sqrt(pow(r1,2) + pow(r2,2));
	}

	float Ch;
};



#endif /* CUBIC_KERNEL_H_ */
