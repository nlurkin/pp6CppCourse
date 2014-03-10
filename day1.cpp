/*
 * day1.cpp
 *
 *  Created on: 10 Mar 2014
 *      Author: ncl
 */

#include "pp6menu.hpp"
#include <iostream>
#include "PP6Math.hpp"

static const int nd1Menu = 9;
static const std::string d1Menu[nd1Menu] = {
		"1) /","2) *","3) +","4) -","5) Quadratic equation solver",
		"6) 3-vector magnitude","7) Line intercept with x axis","8) 4-vector magnitude",
		"9) Invariant mass"};


bool executeday1(){
	//Prepare some arrays to store the input/output values
	float v2[2];				//2 input values
	float v3[3],v3bis[3];		//3 input values
	float v4[4];				//4 input values
	float result, result2[2];	//1 or 2 output values

	int selection;				//Storing the operation chosen by user
	bool printArray;			//Is the result an array or a single value

	while(true){ //Infinite loop. Exit when user inputs 'q'
		printArray = false;

		if(!printAndRequestTopMenu("Day 1 Menu: ", d1Menu, nd1Menu, true, selection)) continue;


		if(selection<0){}
		else if(selection<=4){	// Simple operators with two operands (+-*/)
			std::cout << "Please enter two numbers:" << std::endl;
			if(!inputNumber(v2[0])) continue;
			if(!inputNumber(v2[1])) continue;
		}
		else if(selection<=6){	// Operations requiring 3 input values (quadratic equation, 3-vector)
			std::cout << "Please enter three numbers (a,b,c):" << std::endl;
			if(!inputNumber(v3[0])) continue;
			if(!inputNumber(v3[1])) continue;
			if(!inputNumber(v3[2])) continue;
		}
		else if(selection<=8){	// Operations requiring 4 input values (line intercept, 4-vector)
			std::cout << "Please enter four numbers (x1,y1,x2,y2):" << std::endl;
			if(!inputNumber(v4[0])) continue;
			if(!inputNumber(v4[1])) continue;
			if(!inputNumber(v4[2])) continue;
			if(!inputNumber(v4[3])) continue;
		}
		else if(selection==8){	// More complex operation requiring many input values (invariant mass)
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
		}
		else{	// User introduced rubish
			std::cout << "Unknown operation " << std::endl;
			continue;
		}

		switch(selection){
		case 1:
			if(!div(result,v2[0],v2[1])) continue;
			break;
		case 2:
			if(!mul(result,v2[0],v2[1])) continue;
			break;
		case 3:
			if(!add(result,v2[0],v2[1])) continue;
			break;
		case 4:
			if(!sub(result,v2[0],v2[1])) continue;
			break;
		case 5:
			if(!quadSolve(result2, v3[0], v3[1], v3[2])) continue;
			printArray = true;
			break;
		case 6:
			if(!magVector3(result, v3[0], v3[1], v3[2])) continue;
			break;
		case 7:
			if(!intercept(result, v4[0], v4[1], v4[2], v4[3])) continue;
			break;
		case 8:
			if(!magVector4(result, v4[0],v4[1],v4[2],v4[3])) continue;
			break;
		case 9:
			if(!invMass(result, v2[0], v2[1], v3, v3bis)) continue;
			break;
		case -1:
			return false;
			break;
		case -2:
			return true;
			break;
		default:
			std::cout << "Unknown operation " << selection << std::endl;
			continue;
			break;
		}

		//Print the result
		if(printArray){
			std::cout << "The result is " << result2[0] << "," << result2[1] << std::endl;
		}
		else{
			std::cout << "The result is " << result << std::endl;
		}
	}

	return false;
}


