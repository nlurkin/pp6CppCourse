#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include <iostream>
#include "ThreeVector.hpp"

extern const double celerity;

/**
 * Class representing a 4-vector (1 time component and 3 space components)
 */
class FourVector{
public:
	enum CausalType {kSPACELIKE, kTIMELIKE, kNULL};

	FourVector():fSpace(),fT(0){};
	FourVector(double x, double y, double z, double t);
	FourVector(const FourVector& v):fSpace(v.fSpace),fT(v.fT),fLength(v.fLength){};

	~FourVector(){};
	
	void setXYZT(double x, double y, double z, double t);
	void boostZ(double v);
	
	double getLength() const{ return fLength;};
	CausalType getType() const;

	double getX() const { return fSpace.getX();};
	double getY() const { return fSpace.getY();};
	double getZ() const { return fSpace.getZ();};
	double getT() const;

	FourVector& operator+=(const FourVector& rhs);
	FourVector& operator-=(const FourVector& rhs);
	FourVector& operator=(const FourVector& rhs);
private:
	void computeLength();

	ThreeVector fSpace;
	double fT;
	double fLength;
};

std::ostream& operator<<(std::ostream& stream, const FourVector& v);
std::istream& operator>>(std::istream& stream, FourVector& v);

FourVector operator+(const FourVector& v1, const FourVector& v2);
FourVector operator-(const FourVector& v1, const FourVector& v2);
#endif
