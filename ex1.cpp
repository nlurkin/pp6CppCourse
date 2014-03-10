#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include "PP6Math.hpp"

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

		std::cout << "Please enter an operation (/,*,+,-,4intercept,3quadsolve,3vecmag,4vecmag,invmass,test,q):" << std::endl;
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
		else if(op.compare("test")==0){
			double arr[6] = {5.2,10.3,4.7,8,6,5.21};
			bubbleSort(6, arr);
			for(int i=0; i<6;++i){
				std::cout << arr[i] << ",";
			}
			std::cout << std::endl;
			continue;
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

