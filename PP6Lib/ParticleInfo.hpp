/*
 * ParticleInfo.h
 *
 *  Created on: Mar 26, 2014
 *      Author: nlurkin
 */

#ifndef PARTICLEINFO_H_
#define PARTICLEINFO_H_

#include <iostream>
#include <vector>

class ParticleInfo {
public:
	ParticleInfo(std::string &fileName);
	ParticleInfo(const char* fileName);
	virtual ~ParticleInfo();

	int getPDGCode(std::string name);
	int getCharge(int pdgID);
	std::string getName(int pdgID);
	double getMassMeV(int pdgID);
	double getMassGeV(int pdgID);

	void print();
private:
	ParticleInfo(ParticleInfo& p);
	ParticleInfo& operator=(ParticleInfo& p);

	int findIndex(int pdgID);
	void readData();

	std::string fFileName;
	std::vector<std::string> fName;
	std::vector<int> fPDGCode;
	std::vector<int> fQ;
	std::vector<double> fMassMeV;
};

#endif /* PARTICLEINFO_H_ */
