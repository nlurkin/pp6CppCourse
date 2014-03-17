#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "FourVector.hpp"

/**
 * Class representing a particle.
 */
class Particle{
public:
	Particle();
	Particle(const Particle& p);
	Particle(const Particle& p1, const Particle& p2);
	Particle(double mass, double px, double py, double pz, int index);
	~Particle();

	static Particle generate(double mass, double sigma, double pmin, double pmax, double slope);
	void setP(const FourVector& p) { fP=p;};

	double getEnergy() const { return fP.getT();};
	Particle getDaughter(int ind);
	double getMass() const { return fP.getLength();};
	int getIndex() const { return fIndex;};

	Particle& operator=(const Particle& rhs);
private:
	FourVector fP;
	Particle *fDaughter1, *fDaughter2;
	int fIndex;
};

#endif
