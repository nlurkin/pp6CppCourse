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
#include "FourVector.hpp"

// Module menu definition
static const int nd3Menu = 2;
static const std::string d3Menu[nd3Menu] = {"1) Get 4-vector length", "2) Boost 4-vector"};

const double celerity = 1.;

bool executeday3(){
	double vz;
	FourVector vec;
	int selection;

	while(true){ //Infinite loop. Exit when user inputs 'q'

		//Print menu and wait for user input
		if(!printAndRequestTopMenu("Day 3 Menu: ", d3Menu, nd3Menu, true, selection)) continue;


		// How many input do we request to the user
		if(selection<0){}
		else if(selection==1){
			std::cout << "Please enter four numbers:" << std::endl;
			if(!inputFourVector(vec)) continue;
		}
		else if(selection==2){
			std::cout << "Please enter five numbers:" << std::endl;
			if(!inputFourVector(vec)) continue;
			if(!inputNumber(vz)) continue;
		}
		else{	// User introduced rubbish
			std::cout << "Unknown operation " << std::endl;
			continue;
		}

		//Select the correct operation
		switch(selection){
		case 1:
			std::cout << "The 4-vector length is " << vec.getLength() << " and is of type " << vec.getType() << std::endl;
			break;
		case 2:
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


