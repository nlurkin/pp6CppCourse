/*
 * day4.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: nlurkin
 */

#include "day4.hpp"
#include "pp6menu.hpp"
#include <iostream>
#include <vector>
#include "ParticleInfo.hpp"
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include "Particle.hpp"

// Module menu definition
static const int nd4Menu = 3;
static const std::string d4Menu[nd4Menu] = {"1) Print pdg.dat", "2) Random vector operations", "3) Analyze vector data"};
static ParticleInfo pdgDict("pdg.dat");

/**
 * Output for the particle
 * Params: stream: Output stream
 *         p: particle to print
 * Return: Reference to the output stream
 */
std::ostream& operator<<(std::ostream& stream, const Particle* const p){
	stream.precision(7);
	stream << std::fixed << "\t" << p->getMass() << "\t(" << p->getDaughter(0).getIndex() << "," << p->getDaughter(1).getIndex() << ")";
	return stream;
}

/**
 * Compare particle masses
 * @param p1
 * @param p2
 * @return
 */
bool heavier(Particle* p1, Particle *p2){
	return (p1->getMass()>p2->getMass());
}

/**
 * Compute the invariant mass for all possible mu+/mu- combinations
 * Params: nmup: Number of mu+
 *         mup: Array containing mu+ Particle
 *         nmum: Number of mu-
 *         mum: Array containing mu- Particle
 *         vParent: Reference to an array to store the parent particle
 */
bool combine(const std::vector<Particle*>& mup, const std::vector<Particle*>& mum, std::vector<Particle*>& vParent){
	for(auto p1:mup){
		for(auto p2:mum){
			vParent.push_back(new Particle(*p1,*p2));
		}
	}
	return true;
}

/**
 * Read the observedparticles.dat file and print the 10 highest invariant mass for all possible
 * combination of mu+/mu- in run4.
 * Return: true when no error occurred
 */
bool analyzeVectorData(){
	int event;
	std::string pName;
	double px,py,pz;
	std::string source;
	int indp=0, indm=0;

	std::vector<Particle*> vmp;
	std::vector<Particle*> vmm;
	std::vector<Particle*> parent;

	ParticleInfo pInfo("pdg.dat");

	// Open the file to be read
	FileReader f("observedparticles.dat");

	// Only process if the file is open/valid
	if(!f.isValid()) return false;

	//Skip header line
	f.nextLine();

	// Loop until out of lines
	while (f.nextLine()) {
		event = f.getField<int>(1);
		pName = f.getField<std::string>(2);
		px = f.getField<double>(3);
		py = f.getField<double>(4);
		pz = f.getField<double>(5);
		source = f.getField<std::string>(6);

		if(source == "run4.dat"){
			if(pName == "mu+"){
				vmp.push_back(new Particle(pInfo.getMassMeV(-13), px, py, pz, indp));
				++indp;
			}
			else if(pName == "mu-"){
				vmm.push_back(new Particle(pInfo.getMassMeV(13), px, py, pz, indm));
				++indm;
			}
		}
	}

	combine(vmp, vmm, parent);	// Compute invariant mass for all possible combination

	std::sort(parent.begin(), parent.end(), heavier);
	std::cout << "Number of combinations: " << parent.size() << "(" << vmp.size() << "*" << vmm.size() << ")" << std::endl;
	std::cout << "Highest Invariant masses are: " << std::endl;
	std::cout << "\tInvMass\t\tCombination(mu+,mu-)" << std::endl;

	std::copy(parent.begin(), parent.begin()+10, std::ostream_iterator<Particle*>(std::cout, "\n"));

	return true;
}


int genFlat(){
	return (rand()/(double)RAND_MAX)*100;
}

void doThing(){
	std::vector<int> values(10,0);

	std::generate(values.begin(), values.end(), genFlat);

	std::copy(values.begin(), values.end(), std::ostream_iterator<int>(std::cout, "\n"));

	auto minmax = std::minmax(values.begin(), values.end());

	std::cout << "Min=" << *minmax.first << "\tMax=" << *minmax.second << std::endl;

	std::sort(values.begin(), values.end());
	std::cout << "Sorted vector " << std::endl;
	std::copy(values.begin(), values.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

bool executeday4(){
	int selection;

	while(true){ //Infinite loop. Exit when user inputs 'q'

		//Print menu and wait for user input
		if(!printAndRequestTopMenu("Day 4 Menu: ", d4Menu, nd4Menu, true, selection)) continue;

		// How many input do we request to the user
		if(selection<0){}
		else if(selection>3){
			// User introduced rubbish
			std::cout << "Unknown operation " << std::endl;
			continue;
		}

		//Select the correct operation
		switch(selection){
		case 1:
			pdgDict.print();
			break;
		case 2:
			doThing();
			break;
		case 3:
			analyzeVectorData();
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


