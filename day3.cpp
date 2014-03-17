/*
 * day3.cpp
 *
 *  Created on: 17 Mar 2014
 *      Author: ncl
 */
#include <iostream>
#include <iomanip>
#include <cmath>

#include "day3.hpp"
#include "pp6menu.hpp"
#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "quadVector.hpp"

// Module menu definition
static const int nd3Menu = 2;
static const std::string d3Menu[nd3Menu] = {"1) Get 4-vector length", "2) Boost 4-vector"};

const double celerity = 3e8;

bool executeday3(){
	double v4[4];
	double vz;
	QuadVector vec;
	int selection;

	while(true){ //Infinite loop. Exit when user inputs 'q'

		//Print menu and wait for user input
		if(!printAndRequestTopMenu("Day 3 Menu: ", d3Menu, nd3Menu, true, selection)) continue;


		// How many input do we request to the user
		if(selection<0){}
		else if(selection==1){
			std::cout << "Please enter four numbers:" << std::endl;
			if(!inputNumber(v4[0])) continue;
			if(!inputNumber(v4[1])) continue;
			if(!inputNumber(v4[2])) continue;
			if(!inputNumber(v4[3])) continue;
		}
		else if(selection==2){
			std::cout << "Please enter five numbers:" << std::endl;
			if(!inputNumber(v4[0])) continue;
			if(!inputNumber(v4[1])) continue;
			if(!inputNumber(v4[2])) continue;
			if(!inputNumber(v4[3])) continue;
			if(!inputNumber(vz)) continue;
		}
		else{	// User introduced rubbish
			std::cout << "Unknown operation " << std::endl;
			continue;
		}

		//Select the correct operation
		switch(selection){
		case 1:
			vec.setXYZT(v4[0],v4[1],v4[2],v4[3]);
			std::cout << "The 4-vector length is " << vec.getLength() << " and is of type " << vec.getType() << std::endl;
			break;
		case 2:
			vec.setXYZT(v4[0],v4[1],v4[2],v4[3]);
			vec.boostZ(vz);
			std::cout << "The boosted 4-vector is " << vec << std::endl;
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


