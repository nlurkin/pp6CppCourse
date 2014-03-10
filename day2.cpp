/*
 * day2.cpp
 *
 *  Created on: 10 Mar 2014
 *      Author: ncl
 */
#include <iostream>

#include "day2.hpp"
#include "pp6menu.hpp"
#include "PP6Math.hpp"

static const int nd2Menu = 1;
static const std::string d2Menu[nd2Menu] = {"1) Generate 100 random events"};


bool executeday2(){
	//Prepare some arrays to store the input/output values
	float v2[2];				//2 input values

	int selection;				//Storing the operation chosen by user

	double vMass[100];
	double vPx[100];
	double vPy[100];
	double vPz[100];
	double vE[100];

	while(true){ //Infinite loop. Exit when user inputs 'q'
		if(!printAndRequestTopMenu("Day 2 Menu: ", d2Menu, nd2Menu, true, selection)) continue;


		if(selection<0){}
		else if(selection==1){
			std::cout << "Please enter two numbers:" << std::endl;
			if(!inputNumber(v2[0])) continue;
			if(!inputNumber(v2[1])) continue;
		}
		else{	// User introduced rubbish
			std::cout << "Unknown operation " << std::endl;
			continue;
		}

		switch(selection){
		case 1:
			if(!generateEvent(vMass, vPx, vPy, vPz, vE, v2[0],v2[1])) continue;
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
	}

	return false;
}


