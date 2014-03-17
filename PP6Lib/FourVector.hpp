#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include <iostream>

extern const double celerity;

class FourVector{
public:
	enum CausalType {kSPACELIKE, kTIMELIKE, kNULL};

	FourVector():fX(0),fY(0),fZ(0),fT(0){};
	FourVector(double x, double y, double z, double t);
	FourVector(const FourVector& v):fX(v.fX),fY(v.fY),fZ(v.fZ),fT(v.fT),fLength(v.fLength){};

	~FourVector(){};
	
	void setXYZT(double x, double y, double z, double t);
	void boostZ(double v);
	double getLength() const{ return fLength;};
	CausalType getType() const;

	double getX() const { return fX;};
	double getY() const { return fY;};
	double getZ() const { return fZ;};
	double getT() const;

	FourVector& operator+=(const FourVector& rhs);
	FourVector& operator-=(const FourVector& rhs);
	FourVector& operator=(const FourVector& rhs);
private:
	void computeLength();

	double fX,fY,fZ,fT;
	double fLength;
};

std::ostream& operator<<(std::ostream& stream, const FourVector& v);
std::istream& operator>>(std::istream& stream, FourVector& v);

FourVector operator+(const FourVector& v1, const FourVector& v2);
FourVector operator-(const FourVector& v1, const FourVector& v2);
#endif
