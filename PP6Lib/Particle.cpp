#include "Particle.hpp"
#include "PP6Math.hpp"
#include <cmath>

/**
 * Default constructor. No index and no daughter particle.
 */
Particle::Particle():
fP(),fDaughter1(NULL), fDaughter2(NULL), fIndex(-1)
{
}

/**
 * Copy-constructor. If the copied particle has daughters, they are copied as daughter of this one.
 */
Particle::Particle(const Particle& p){
	fP = p.fP;
	if(p.fDaughter1==NULL) fDaughter1 = NULL;
	else *fDaughter1 = *p.fDaughter1;

	if(p.fDaughter2==NULL) fDaughter2 = NULL;
	else *fDaughter2 = *p.fDaughter2;
	
	fIndex = p.fIndex;	
}

/**
 * Constructor from daughter particle. Particle with no index and mass 
 * from invariant mass of daughter particles. Daughter particles are
 * copied.
 */
Particle::Particle(const Particle& p1, const Particle& p2):
fP(p1.fP+p2.fP),fDaughter1(new Particle(p1)), fDaughter2(new Particle(p2)),fIndex(-1)
{
}

/**
 * Constructor. Initialize particle momentum, energy and index. No daughter particle.
 */
Particle::Particle(double mass, double px, double py, double pz,int index):
fP(px,py,pz,sqrt(mass*mass+px*px+py*py+pz*pz)), fDaughter1(0), fDaughter2(0),fIndex(index)
{
}

/**
 * Destructor. Delete daughter if exist.
 */
Particle::~Particle(){
	if(fDaughter1) delete fDaughter1;
	if(fDaughter2) delete fDaughter2;
}

/**
 * Static method.
 * Generate a new particle with gaussian random mass and random momentum.
 * Params: mass: Mean of the gaussian
 *         sigma: Standard deviation of the gaussian
 *         pmin,pmax: Minimum and maximum of the magnitude of the momentum
 *         slope: Maximum slope of the momentum
 * Return: New particle
 */
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

/**
 * Get the daughter particle.
 * Params: index: 0 or 1. To get the first or second daughter particle.
 * Return: The daughter particle if exist. A blank particle if not.
 */
Particle Particle::getDaughter(int index){
	if(index==0) return *fDaughter1;
	else if(index==1) return *fDaughter2;
	else return Particle();
}

/**
 * particle copy assignment operator. Create a copy of the daughter if exist.
 * Params: rhs: Particle to copy
 * Return: Reference to this particle.
 */
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

