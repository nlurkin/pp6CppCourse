#include <iostream>
#include <limits>
#include <string>
#include <cmath>

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
	if(b==0){
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
	if((y2-y1)==0){
		std::cout << "Unable to compute intercept with x. Line is parallel to x axis." << std::endl;
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
bool quadSolve(float (&x)[2], float a, float b, float c){
	float delta;
	delta = b*b-4*a*c;
	if(delta<0){
		std::cout << "Unable to solve quadratic equation. Delta<0." << std::endl;
		x[0] = 0;
		x[1] = 0;
		return false;
	}
	else if(delta==0){
		x[0] = -b/(2*a);
		x[1] = 0;
	}
	else{
		x[0] = (-b+sqrt(delta))/(2*a);
		x[1] = (-b-sqrt(delta))/(2*a);
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

	if(!magVector3(p1Mag,p1[0],p1[1],p1[2]) || !magVector3(p2Mag,p2[0],p2[1],p2[2])){
		std::cout << "Invalid momenta magnitude." << std::endl;
		return false;
	}

	E1 = sqrt(m1*m1 + p1Mag*p1Mag);
	E2 = sqrt(m2*m2 + p2Mag*p2Mag);
	dotProduct = sqrt(p1[0]*p2[0] + p1[1]*p2[1] + p1[2]*p2[2]);
	mass = sqrt(m1*m1 + m2*m2 + 2*(E1*E2 - dotProduct));
	return true;
}

/**
 * Wait for a number in cin. Print an error message if the input is not a number.
 * Params: number
 * Return: true if input can be parsed as float
 */
bool inputNumber(float &number){
	std::cin >> number;
   if(!std::cin){
		std::cout << "There is a problem with your input" << std::endl;
		return false;
	}
	return true;
}

int main(){
	//Prepare some arrays to store the input/output values
	float v2[2];					//2 input values
	float v3[3],v3bis[3];		//3 input values
	float v4[4];					//4 input values
	float result, result2[2];	//1 or 2 output values

	std::string op;				//Storing the operation chosen by the user
	bool printArray;				//Is the result an array or a single value

	std::cout << "Hello world!" << std::endl;

	while(true){ //Infinite loop. Exit when user inputs 'q'

		//Clear the input stream flags and values in case of error
		if(!std::cin){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		printArray = false;

		std::cout << "Please enter an operation (/,*,+,-,4intercept,3quadsolve,3vecmag,4vecmag,invmass,q):" << std::endl;
		std::cin >> op;
		if(!std::cin){
			std::cout << "There is an error with the operation you entered" << std::endl;
			continue;
		}

		//Quit
		if(op.compare("q")==0) break;

		if(op.length()==1){		// Simple operators with two operands (+-*/)
			std::cout << "Please enter two numbers:" << std::endl;
			if(!inputNumber(v2[0])) continue;
			if(!inputNumber(v2[1])) continue;
		
			if(op.compare("/")==0){
				if(!div(result,v2[0],v2[1])) continue;
			}
			else if(op.compare("*")==0){
				if(!mul(result,v2[0],v2[1])) continue;
			}
			else if(op.compare("+")==0){
				if(!add(result,v2[0],v2[1])) continue;
			}
			else if(op.compare("-")==0){
				if(!sub(result,v2[0],v2[1])) continue;
			}
			else{
				std::cout << "Unknown operation " << op << std::endl;
				continue;
			}
		}
		else if(op[0]=='3'){		// OPerations requiring 3 input values (quadratic equation, 3-vector)
			std::cout << "Please enter three numbers (a,b,c):" << std::endl;
			if(!inputNumber(v3[0])) continue;
			if(!inputNumber(v3[1])) continue;
			if(!inputNumber(v3[2])) continue;

			if(op.compare("3quadsolve")==0){
				if(!quadSolve(result2, v3[0], v3[1], v3[2])) continue;
				printArray = true;
			}
			else if(op.compare("3vecmag")==0){
				if(!magVector3(result, v3[0], v3[1], v3[2])) continue;
			}
		}
		else if(op[0]=='4'){		// Operations requiring 4 input values (line intercept, 4-vector)
			std::cout << "Please enter four numbers (x1,y1,x2,y2):" << std::endl;
			if(!inputNumber(v4[0])) continue;
			if(!inputNumber(v4[1])) continue;
			if(!inputNumber(v4[2])) continue;
			if(!inputNumber(v4[3])) continue;
		
			if(op.compare("4intercept")==0){
				if(!intercept(result, v4[0], v4[1], v4[2], v4[3])) continue;
			}
			else if(op.compare("4vecmag")==0){
				if(!magVector4(result, v4[0],v4[1],v4[2],v4[3])) continue;
			}
		}
		else if(op.compare("invmass")==0){	// More complex operation requiring many input values (invariant mass)
			std::cout << "Please enter the particle masses (m1,m2)" << std::endl;
			if(!inputNumber(v2[0])) continue;
			if(!inputNumber(v2[1])) continue;
			std::cout << "Please enter the first particle momentum (x1,y1,z1)" << std::endl;
			if(!inputNumber(v3[0])) continue;
			if(!inputNumber(v3[1])) continue;
			if(!inputNumber(v3[2])) continue;
			std::cout << "Please enter the second particle momentum (x2,y2,z2)" << std::endl;
			if(!inputNumber(v3bis[0])) continue;
			if(!inputNumber(v3bis[1])) continue;
			if(!inputNumber(v3bis[2])) continue;

			if(!invMass(result, v2[0], v2[1], v3, v3bis)) continue;
		}
		else{	// User introduced rubish
			std::cout << "Unknown operation " << op << std::endl;
			continue;
		}

		//Print the result
		if(printArray){
			std::cout << "The result is " << result2[0] << "," << result2[1] << std::endl;
		}
		else{
			std::cout << "The result is " << result << std::endl;
		}
	}
	return 0;
}

