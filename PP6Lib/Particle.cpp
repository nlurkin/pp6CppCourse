#include "Particle.hpp"
#include "PP6Math.hpp"
#include <cmath>

Particle::Particle():
fP(),fDaughter1(NULL), fDaughter2(NULL), fIndex(-1)
{
}

Particle::Particle(const Particle& p){
	fP = p.fP;
	if(p.fDaughter1==NULL) fDaughter1 = NULL;
	else *fDaughter1 = *p.fDaughter1;

	if(p.fDaughter2==NULL) fDaughter2 = NULL;
	else *fDaughter2 = *p.fDaughter2;
	
	fIndex = p.fIndex;	
}

Particle::Particle(const Particle& p1, const Particle& p2):
fP(p1.fP+p2.fP),fDaughter1(new Particle(p1)), fDaughter2(new Particle(p2)),fIndex(-1)
{
}

Particle::Particle(double mass, double px, double py, double pz,int index):
fP(px,py,pz,sqrt(mass*mass+px*px+py*py+pz*pz)), fDaughter1(0), fDaughter2(0),fIndex(index)
{
}

Particle::~Particle(){
	if(fDaughter1) delete fDaughter1;
	if(fDaughter2) delete fDaughter2;
}

Particle Particle::generate(double mass, double sigma, double pmin, double pmax, double slope){
	Particle r;
	double rMass;
	double pmag, px, py, pz;
	double dxdz, dydz;
	double unitLength;
	double energy;

	gauss(rMass, mass, sigma);

	flat(pmag, pmin,pmax);
	flat(dxdz, 0, slope);
	flat(dydz, 0, slope);
	magVector3(unitLength, dxdz, dydz, 1.0);

	px = dxdz*(pmag/unitLength);
	py = dydz*(pmag/unitLength);
	pz = pmag/unitLength;

	energy = sqrt(rMass*rMass + pmag*pmag);

	r.setP(FourVector(px,py,pz,energy));
	
	return r;
}

Particle Particle::getDaughter(int index){
	if(index==0) return *fDaughter1;
	else if(index==1) return *fDaughter2;
	else return Particle();
}

Particle& Particle::operator=(const Particle& rhs){
	if(&rhs==this) return *this;
	fP = rhs.fP;
	if(rhs.fDaughter1==NULL) fDaughter1 = NULL;
	else *fDaughter1 = *rhs.fDaughter1;

	if(rhs.fDaughter2==NULL) fDaughter2 = NULL;
	else *fDaughter2 = *rhs.fDaughter2;
	
	fIndex = rhs.fIndex;
	return *this;
}

/*Particle& Particle::operator=(const Particle *const rhs){
	if(rhs==this) return *this;
	fP = rhs->fP;
	if(rhs->fDaugher[0]==NULL) fDaughter[0] = NULL;
	else *fDaughter[0] = *rhs->fDaughter[0];

	if(rhs->fDaugher[1]==NULL) fDaughter[1] = NULL;
	else *fDaughter[1] = *rhs->fDaughter[1];
	
	fIndex = rhs->fIndex;
	return *this;
}*/

