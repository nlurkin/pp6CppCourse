/*
 * day2.cpp
 *
 *  Created on: 10 Mar 2014
 *      Author: ncl
 */
#include <iostream>
#include <iomanip>
#include <cmath>

#include "day2.hpp"
#include "pp6menu.hpp"
#include "PP6Math.hpp"
#include "FileReader.hpp"

// Module menu definition
static const int nd2Menu = 2;
static const std::string d2Menu[nd2Menu] = {"1) Generate 100 random events","2) Analyze observedparticles.dat"};

static const int arrSize = 500; // Max array size for muon container (setting this value too high will segfault, mass combination is arrSize^2)
static const double muMass = 105.6583715; // Mass of the muon (assuming momenta from input files in MeV/c^2)

/**
 * Check if an error occured while reading the input file.
 * Params: f: reader processing the file
 * Return: true if no error detected, false otherwise
 */
bool checkInput(FileReader& f){
	if(f.inputFailed()){
		std::cout << "[error] A problem occurred while reading the input file." << std::endl;
		return false;
	}
	return true;
}

/**
 * Compute the invariant mass for all possible mu+/mu- combinations
 * Params: nmup: Number of mu+
 *         mup: Array containing mu+ momentums (3 components)
 *         nmum: Number of mu-
 *         mum: Array containing mu- momentums (3 components)
 *         vInvMass: Reference to an array to store the invariant masses
 */
bool combine(int nmup, double mup[][3], int nmum, double mum[][3], double (&vInvMass)[arrSize*arrSize]){
	double mass;

	for(int i=0; i<nmup; ++i){
		for(int j=0; j<nmum; ++j){
			invMass(mass, muMass, muMass, mup[i], mum[j]);
			vInvMass[i*nmum + j] = mass;
		}
	}
	return true;
}

/**
 * Read the observedparticles.dat file and print the 10 highest invariant mass for all possible
 * combination of mu+/mu- in run4.
 * Return: true when no error occurred
 */
bool analyzeData(){
	int event;
	std::string pName;
	double px,py,pz;
	std::string source;

	double vmpP[arrSize][3];
	double vmmP[arrSize][3];
	int mpCount=0, mmCount=0;
	double invMass[arrSize*arrSize];
	int mIndices[arrSize*arrSize];

	// Open the file to be read
	FileReader f("observedparticles.dat");

	// Only process if the file is open/valid
	if(!f.isValid()) return false;

	//Skip header line
	f.nextLine();

	// Loop until out of lines
	while (f.nextLine()) {
		event = f.getFieldAsInt(1);
		if(!checkInput(f)) return false;
		pName = f.getFieldAsString(2);
		if(!checkInput(f)) return false;
		px = f.getFieldAsDouble(3);
		if(!checkInput(f)) return false;
		py = f.getFieldAsDouble(4);
		if(!checkInput(f)) return false;
		pz = f.getFieldAsDouble(5);
		if(!checkInput(f)) return false;
		source = f.getFieldAsString(6);

		if(source.compare("run4.dat")==0){
			if(pName.compare("mu+")){
				if(mpCount>=arrSize){	// Check if we are not going out of bounds
					std::cout << "[error] Too many entries for fixed size array (" << arrSize << ")" << std::endl;
					return false;
				}
				vmpP[mpCount][0] = px;
				vmpP[mpCount][1] = py;
				vmpP[mpCount][2] = pz;
				++mpCount;
			}
			else if(pName.compare("mu-")){
				if(mmCount>=arrSize){	// Check if we are not going out of bounds
					std::cout << "[error] Too many entries for fixed size array (" << arrSize << ")" << std::endl;
					return false;
				}
				vmmP[mmCount][0] = px;
				vmmP[mmCount][1] = py;
				vmmP[mmCount][2] = pz;
				++mmCount;
			}
		}
	}

	combine(mpCount, vmpP, mmCount, vmmP, invMass);	// Compute invariant mass for all possible combination

	bubbleSortIndex(mpCount*mmCount, invMass, mIndices);	// Sort the invariant masses (and keep track of indices)

	std::cout << "Highest Invariant masses are : " << std::endl;
	std::cout << "\tInvMass\t\tCombination(mu+,mu-)" << std::endl;
	int indmp, indmm;
	for(int i=0; (i<10) && (i<(mpCount*mmCount)); ++i){
		indmp = int(mIndices[i]/mmCount);
		indmm = mIndices[i] % mmCount;
		std::cout.precision(7);
		std::cout << std::fixed << "\t" << invMass[i] << "\t(" << indmp << "," << indmm << ")" << std::endl;
	}

	return true;
}

/**
 * Generate 100 random events.
 * Params: eMean: Mean energy
 *         eSigma: standard deviation of the energy
 *         mass: mean mass of the generated particles
 *         sigma: standard deviation of the masses of the generated particles
 * Return: true if no error occured
 */
bool randomEvents(double& eMean, double& eSigma, double mass, double sigma){
	double vMass[100];
	double vP[100][3];
	double vE[100];

	eMean = 0;
	eSigma = 0;

	//Generate the 100 random events
	if(!generateEvent(vMass, vP, vE, mass,sigma)) return false;

	//Compute the mean energy
	for(int i=0; i<100;++i){
		eMean += vE[i];
	}
	eMean /= 100.;

	//Compute the standard deviation of the energy
	for(int i=0; i<100;++i){
		eSigma += pow(vE[i]-eMean,2);
	}
	eSigma = sqrt(eSigma/99.);

	return true;
}

bool executeday2(){
	//Prepare some arrays to store the input/output values
	float v2[2];				//2 input values

	double result[2];			//Store the results
	int selection;				//Storing the operation chosen by user

	while(true){ //Infinite loop. Exit when user inputs 'q'

		//Print menu and wait for user input
		if(!printAndRequestTopMenu("Day 2 Menu: ", d2Menu, nd2Menu, true, selection)) continue;


		// How many input do we request to the user
		if(selection<0){}
		else if(selection==1){
			std::cout << "Please enter two numbers:" << std::endl;
			if(!inputNumber(v2[0])) continue;
			if(!inputNumber(v2[1])) continue;
		}
		else if(selection==2){}
		else{	// User introduced rubbish
			std::cout << "Unknown operation " << std::endl;
			continue;
		}

		//Select the correct operation
		switch(selection){
		case 1:
			if(!randomEvents(result[0], result[1], v2[0],v2[1])) continue;
			std::cout << "100 random events generated." << std::endl;
			std::cout << "Mean E: " << result[0] << " ; Sigma E: " << result[1] << std::endl;
			break;
		case 2:
			if(!analyzeData()) continue;
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


