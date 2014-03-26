/*
 * ParticleInfo.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: nlurkin
 */

#include "ParticleInfo.hpp"
#include "FileReader.hpp"
#include <algorithm>

ParticleInfo::ParticleInfo(std::string& fileName):
fFileName(fileName)
{
	readData();
}

ParticleInfo::ParticleInfo(const char* fileName):
fFileName(fileName)
{
	readData();
}

void ParticleInfo::readData(){
	FileReader f(fFileName);

	if(f.isValid()){
		while(f.nextLine()){
			fName.push_back(f.getFieldAsString(1));
			fPDGCode.push_back(f.getField<int>(2));
			fQ.push_back(f.getField<int>(3));
			fMassMeV.push_back(f.getField<double>(4));
		}
	}
}

ParticleInfo::~ParticleInfo() {
	// TODO Auto-generated destructor stub
}

int ParticleInfo::getPDGCode(std::string name) {
	int index = std::find(fName.begin(), fName.end(), name) - fName.begin();
	return fPDGCode[index];
}

int ParticleInfo::getCharge(int pdgID) {
	return fQ[findIndex(pdgID)];
}

std::string ParticleInfo::getName(int pdgID) {
	return fName[findIndex(pdgID)];
}

double ParticleInfo::getMassMeV(int pdgID) {
	return fMassMeV[findIndex(pdgID)];
}

double ParticleInfo::getMassGeV(int pdgID) {
	return fMassMeV[findIndex(pdgID)]/1000.;
}

void ParticleInfo::print() {
	std::cout << fName.size() << "\t" << fPDGCode.size() << "\t" << fQ.size() << "\t" << fMassMeV.size() << std::endl;
	std::cout << "----------------------------------" << std::endl;
	auto id = fPDGCode.begin();
	auto s = fQ.begin();
	auto m = fMassMeV.begin();
	for(auto name : fName){
		std::cout << name << "\t" << *id << "\t" << *s << "\t" << *m << std::endl;
		++id;
		++s;
		++m;
	}
}

int ParticleInfo::findIndex(int pdgID) {
	return std::find(fPDGCode.begin(), fPDGCode.end(), pdgID) - fPDGCode.begin();
}
