#include "ThreeVector.hpp"
#include <math.h>

ThreeVector::ThreeVector(double x, double y, double z):
fX(x),fY(y),fZ(z)
{
	computeLength();
}

void ThreeVector::setXYZ(double x, double y, double z){
	fX = x;
	fY = y;
	fZ = z;

	computeLength();
}

void ThreeVector::computeLength(){
	double lSquare = fX*fX + fY*fY + fZ*fZ;
	fLength = sqrt(lSquare);
}

std::ostream& operator<<(std::ostream& stream, const ThreeVector& v){
	stream << "(" << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
	return stream;
}

std::istream& operator>>(std::istream& stream, ThreeVector& v){
	double x,y,z;
	stream >> x >> y >> z;
	v.setXYZ(x,y,z);
	return stream;
}

ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs){
	fX+= rhs.fX;
	fY+= rhs.fY;
	fZ+= rhs.fZ;

	computeLength();
	return *this;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs){
	fX-= rhs.fX;
	fY-= rhs.fY;
	fZ-= rhs.fZ;

	computeLength();
	return *this;
}

ThreeVector& ThreeVector::operator=(const ThreeVector& rhs){
	if(&rhs==this) return *this;
	fX = rhs.fX;
	fY = rhs.fY;
	fZ = rhs.fZ;
	fLength = rhs.fLength;
	return *this;
}

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs){
	ThreeVector r(lhs);
	r+= rhs;
	return r;
}

ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs){
	ThreeVector r(lhs);
	r-= rhs;
	return r;
}
