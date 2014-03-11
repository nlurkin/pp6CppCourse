#include <cmath>
#include "PP6Math.hpp"
#include <iostream>
#include <cstdlib>

/**
 * Multiply function (c=a*b)
 * Params: c: result of the multiplication
 *         a,b: factors to multiply
 * Return: true if no error happened
 */
bool mul(float &c, float a, float b){
	c = a*b;
	return true;
}
/**
 * Division function (c=a/b)
 * Params: c: result of the division
 *         a: dividend
 *         b: divisor
 * Return: true if no error happened (division by 0)
 */
bool div(float &c, float a, float b){
	if(b==0.0){
		std::cout << "Error division by 0" << std::endl;
		return false;
	}
	c = a/b;
	return true;
}
/**
 * Addition function (c=a+b)
 * Params: c: result of the addition
 *         a,b: terms of the addition
 * Return: true if no error happened
 */
bool add(float &c, float a, float b){
	c = a+b;
	return true;
}
/**
 * Substraction function (c=a-b)
 * Params: c: result of the substraction
 *         a,b: terms of the substraction
 * Return: true if no error happened
 */
bool sub(float &c, float a, float b){
	c = a-b;
	return true;
}

/**
 * Intercept of a line with x axis
 * Params: i: intercept
 *         x1,y1: one point of the line
 *         x2,y2: a second point of the line
 * Return: true if no error happened (line is parallel to x axis)
 */
bool intercept(float &i, float x1, float y1, float x2, float y2){
	float m,p;
	if(isEq(y2-y1,0)){
		std::cout << "Unable to compute intercept with x. Line is parallel to x axis." << std::endl;
		return false;
	}
	if((x2-x1)==0.0){
		std::cout << "Unable to compute intercept with x. Division by 0." << std::endl;
		return false;
	}
	m = (y2-y1)/(x2-x1);
	p = y1-m*x1;
	i = -p/m;
	return true;
}

/**
 * Solve quadratic equation
 * Params: x[2]: an array containing the two possible solutions
 *         a,b,c: the coefficients of the equation: ax^2+bx+c=0
 * Return: true if no error happened (no solution to the equation)
 */
bool quadSolve(float &x1, float &x2, float a, float b, float c){
	float delta;
	delta = b*b-4*a*c;

	//0,1 or 2 solutions?
	if(delta<0){
		std::cout << "Unable to solve quadratic equation. Delta<0." << std::endl;
		x1 = 0;
		x2 = 0;
		return false;
	}
	else if(isEq(delta,0)){
		x1 = -b/(2*a);
		x2 = 0;
	}
	else{
		x1 = (-b+sqrt(delta))/(2*a);
		x2 = (-b-sqrt(delta))/(2*a);
	}
	return true;
}

/**
 * Magnitude of a 3-vector |v|
 * Params: mag: magnitude of the 3-vector
 *         a,b,c: elements of the 3-vector
 * Return: true if no error happened
 */
bool magVector3(float &mag, float a, float b, float c){
	mag = sqrt(a*a+b*b+c*c);
	return true;
}

/**
 * Magnitude of a 3-vector |v|
 * Params: mag: magnitude of the 3-vector
 *         a,b,c: elements of the 3-vector
 * Return: true if no error happened
 */
bool magVector3(double &mag, double a, double b, double c){
	mag = sqrt(a*a+b*b+c*c);
	return true;
}
/**
 * Magnitude of a 4-vector |v|
 * Params: mag: magnitude of the 4-vector
 *         a,b,c,d: elements of the 4-vector
 * Return: true if no error happened (|v|^2 < 0)
 */
bool magVector4(float &mag, float a, float b, float c, float d){
	float mag2;
	mag2 = a*a - b*b - c*c - d*d;
	if(mag2<0){
		std::cout << "Unable to compute 4-vector magnitude. Mag^2 is negative." << std::endl;
		return false;
	}
	mag = sqrt(mag2);
	return true;
}

/**
 * Invariant mass of two particles
 * Params: mass: invariant mass
 *         m1,m2: masses of the two particles
 *         p1,p2: 3-momenta of the two particles
 * Return: true if no error happened
 */
bool invMass(float &mass, float m1, float m2, float p1[3], float p2[3]){
	float E1,E2;
	float p1Mag,p2Mag;
	float dotProduct;
	float msq;

	mass = 0.0;
	//Compute momenta magnitude
	if(!magVector3(p1Mag,p1[0],p1[1],p1[2]) || !magVector3(p2Mag,p2[0],p2[1],p2[2])){
		std::cout << "Invalid momenta magnitude." << std::endl;
		return false;
	}

	//Compute particle energies (m^2 - |p|^2)
	E1 = sqrt(m1*m1 + p1Mag*p1Mag);
	E2 = sqrt(m2*m2 + p2Mag*p2Mag);
	//Compute dot product p1.p2
	dotProduct = sqrt(p1[0]*p2[0] + p1[1]*p2[1] + p1[2]*p2[2]);
	//Compute m^2 and check that it is >0
	msq = m1*m1 + m2*m2 + 2*(E1*E2 - dotProduct);
	if(msq<0){
		std::cout << "[error] Invariant mass squared is negative." << std::endl;
		return false;
	}
	mass = sqrt(msq);
	return true;
}

/**
 * Invariant mass of two particles
 * Params: mass: invariant mass
 *         m1,m2: masses of the two particles
 *         p1,p2: 3-momenta of the two particles
 * Return: true if no error happened
 */
bool invMass(double &mass, double m1, double m2, double p1[3], double p2[3]){
	double E1,E2;
	double p1Mag,p2Mag;
	double dotProduct;
	double msq;

	mass = 0.0;
	//Compute momenta magnitude
	if(!magVector3(p1Mag,p1[0],p1[1],p1[2]) || !magVector3(p2Mag,p2[0],p2[1],p2[2])){
		std::cout << "Invalid momenta magnitude." << std::endl;
		return false;
	}

	//Compute particle energies (m^2 - |p|^2)
	E1 = sqrt(m1*m1 + p1Mag*p1Mag);
	E2 = sqrt(m2*m2 + p2Mag*p2Mag);
	//Compute dot product p1.p2
	dotProduct = sqrt(p1[0]*p2[0] + p1[1]*p2[1] + p1[2]*p2[2]);
	//Compute m^2 and check that it is >0
	msq = m1*m1 + m2*m2 + 2*(E1*E2 - dotProduct);
	if(msq<0){
		std::cout << "[error] Invariant mass squared is negative." << std::endl;
		return false;
	}
	mass = sqrt(msq);
	return true;
}

/**
 * Swap two numbers
 * Params: a,b: numbers to swap
 * Return: true if no error happened
 */
bool swap(double& a, double& b){
	double c = a;
	a = b;
	b = c;
	return true;
}

/**
 * Swap two numbers
 * Params: a,b: numbers to swap
 * Return: true if no error happened
 */
bool swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
	return true;
}

/**
 * Bubble sort algorithm
 * Params: size: Number of elements in the array
 *         arr: reference to array to sort
 * Return: true if no error happened
 */
bool bubbleSort(int size, double *arr){
	int count = -1;
	while(count!=0){	//Loop until number of swap == 0
		count = 0;
		for(int i=0; i<size-1; ++i){
			if(arr[i]<arr[i+1]){
				swap(arr[i],arr[i+1]);
				++count;
			}
		}
	}
	return true;
}

/**
 * Bubble sort algorithm. Fill indArr with the original indices of the elements.
 * Params: size: Number of elements in the array
 *         arr: reference to array to sort
 *         indArr: reference to array of the same size as arr
 * Return: true if no error happened
 */
bool bubbleSortIndex(int size, double *arr, int *indArr){
	int count = -1;

	//Initialize index array
	for(int i=0; i<size-1; ++i){
		indArr[i] = i;
	}

	while(count!=0){	//Loop until number of swap == 0
		count = 0;
		for(int i=0; i<size-1; ++i){
			if(arr[i]<arr[i+1]){
				swap(arr[i],arr[i+1]);
				swap(indArr[i],indArr[i+1]);
				++count;
			}
		}
	}
	return true;
}

/**
 * Floating point numbers comparison
 * Params: a,b: floats to compare
 * Return: true if can be considered equals
 */
bool isEq(float a, float b){
	float epsilon = 10e-8;
	return (fabsf(a-b) < fabsf(b)*epsilon);
}

/**
 * Floating point numbers comparison
 * Params: a,b: floats to compare
 * Return: true if can be considered equals
 */
bool isEq(double a, double b){
	float epsilon = 10e-8;
	return (fabs(a-b) < fabs(b)*epsilon);
}

/**
 * Generate a flat distribution between min and max.
 * Params: rnd: random number following the distribution
 *         min: minimum of the flat distribution
 *         max: maximum of the flat distribution
 */
bool flat(double& rnd, double min, double max) {
	rnd = (rand()/(double)RAND_MAX)*(max-min) + min;
	return true;
}

/**
 * Generate a normal distribution.
 * Params: rnd: random number following the distribution
 */
bool normal(double &rnd) {
	double v1,v2,s;

	do{
		flat(v1,-1,1);
		flat(v2,-1,1);

		s = v1*v1 + v2*v2;
	} while(s>= 1.0);

	if(isEq(s,0.0)) rnd = 0.0;
	else rnd = (v1*sqrt(-2.0*log(s)/s));
	return true;
}

/**
 * Generate a gaussian distribution.
 * Params: rnd: random number following the distribution
 *         mu: mean of the distribution
 *         sigma: sigma of the distribution
 */
bool gauss(double &rnd, double mu, double sigma) {
	normal(rnd);
	rnd = mu + sigma*rnd;
	return true;
}

/**
 * Generate 100 random events with particle mass being a gauss(mass,sigma).
 * The momenta magnitude is a flat distribution between 3 and 75 GeV/c^2.
 * The particle momenta is along z with dxdz and dydz slopes between 0 and 0.5.
 * Params: vMass: array of particle masses
 *         vP: array of momenta (3 components)
 *         vE: array of energies
 *         mass: mean mass of the generated particles
 *         sigma: standard deviation of the generated particle mass
 * Return: true if no error occured
 */
bool generateEvent(double (&vMass)[100], double (&vP)[100][3], double (&vE)[100],double mass, double sigma) {
	double rMass;
	double px,py,pz;
	double energy;
	double pmag,dxdz,dydz;
	double unitLength;

	for(int i=0; i<100; ++i){
		gauss(rMass, mass, sigma);

		flat(pmag, 3,75);
		flat(dxdz, 0, 0.5);
		flat(dydz, 0, 0.5);
		magVector3(unitLength, dxdz, dydz, 1.0);

		px = dxdz*(pmag/unitLength);
		py = dydz*(pmag/unitLength);
		pz = pmag/unitLength;

		energy = sqrt(rMass*rMass + pmag*pmag);

		vMass[i] = rMass;
		vP[i][0] = px;
		vP[i][1] = py;
		vP[i][2] = pz;
		vE[i] = energy;
	}

	return true;
}
