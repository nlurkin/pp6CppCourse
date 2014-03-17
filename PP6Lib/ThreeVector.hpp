#ifndef THREEVECTOR_HPP
#define THREEVECTOR_HPP
#include <iostream>

/**
 * Class representing a 3-vector (3 space components)
 */
class ThreeVector{
public:
	enum CausalType {kSPACELIKE, kTIMELIKE, kNULL};

	ThreeVector():fX(0),fY(0),fZ(0){};
	ThreeVector(double x, double y, double z);
	ThreeVector(const ThreeVector& v):fX(v.fX),fY(v.fY),fZ(v.fZ),fLength(v.fLength){};

	~ThreeVector(){};
	
	void setXYZ(double x, double y, double z);
	double getLength() const{ return fLength;};

	double getX() const { return fX;};
	double getY() const { return fY;};
	double getZ() const { return fZ;};

	ThreeVector& operator+=(const ThreeVector& rhs);
	ThreeVector& operator-=(const ThreeVector& rhs);
	ThreeVector& operator=(const ThreeVector& rhs);
private:
	void computeLength();

	double fX,fY,fZ;
	double fLength;
};

std::ostream& operator<<(std::ostream& stream, const ThreeVector& v);
std::istream& operator>>(std::istream& stream, ThreeVector& v);

ThreeVector operator+(const ThreeVector& v1, const ThreeVector& v2);
ThreeVector operator-(const ThreeVector& v1, const ThreeVector& v2);
#endif
