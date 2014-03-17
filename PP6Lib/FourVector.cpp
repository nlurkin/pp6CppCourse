#include "FourVector.hpp"
#include <math.h>

FourVector::FourVector(double x, double y, double z, double t):
fX(x),fY(y),fZ(z),fT(t)
{
	computeLength();
}

void FourVector::setXYZT(double x, double y, double z, double t){
	fX = x;
	fY = y;
	fZ = z;
	fT = celerity*t;

	computeLength();
}

void FourVector::boostZ(double v){
	double beta = v/celerity;
	double gamma = 1./sqrt(1.-beta*beta);
	double ct = fT;
	fT = gamma*(ct-beta*fZ);
	fZ = gamma*(fZ-beta*ct);
}

void FourVector::computeLength(){
	double lSquare = fT*fT - fX*fX - fY*fY - fZ*fZ;
	if(lSquare<0) fLength = -sqrt(-lSquare);
	else fLength = sqrt(lSquare);
}

FourVector::CausalType FourVector::getType() const{
	if(fLength<0) return kSPACELIKE;
	if(fLength>0) return kTIMELIKE;
	else return kNULL;
}

double FourVector::getT() const{
	return fT/celerity;
}

std::ostream& operator<<(std::ostream& stream, const FourVector& v){
	stream << "(" << v.getT() << "," << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
	return stream;
}

std::istream& operator>>(std::istream& stream, FourVector& v){
	double x,y,z,t;
	stream >> x >> y >> z >> t;
	v.setXYZT(x,y,z,t);
	return stream;
}

FourVector& FourVector::operator+=(const FourVector& rhs){
	fX+= rhs.fX;
	fY+= rhs.fY;
	fZ+= rhs.fZ;
	fT+= rhs.fT;

	computeLength();
	return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs){
	fX-= rhs.fX;
	fY-= rhs.fY;
	fZ-= rhs.fZ;
	fT-= rhs.fT;

	computeLength();
	return *this;
}

FourVector& FourVector::operator=(const FourVector& rhs){
	if(&rhs==this) return *this;
	fX = rhs.fX;
	fY = rhs.fY;
	fZ = rhs.fZ;
	fT = rhs.fT;
	fLength = rhs.fLength;
	return *this;
}

FourVector operator+(const FourVector& lhs, const FourVector& rhs){
	FourVector r(lhs);
	r+= rhs;
	return r;
}

FourVector operator-(const FourVector& lhs, const FourVector& rhs){
	FourVector r(lhs);
	r-= rhs;
	return r;
}
