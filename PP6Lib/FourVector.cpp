#include "FourVector.hpp"
#include <math.h>

FourVector::FourVector(double x, double y, double z, double t):
fSpace(x,y,z),fT(t)
{
	computeLength();
}

void FourVector::setXYZT(double x, double y, double z, double t){
	fSpace.setXYZ(x,y,z);
	fT = celerity*t;

	computeLength();
}

void FourVector::boostZ(double v){
	double beta = v/celerity;
	double gamma = 1./sqrt(1.-beta*beta);
	double ct = fT;
	double z;

	fT = gamma*(ct-beta*fSpace.getZ());
	z = gamma*(fSpace.getZ()-beta*ct);
	fSpace.setXYZ(fSpace.getX(), fSpace.getY(), z);
}

void FourVector::computeLength(){
	double lSquare = fT*fT - fSpace.getLength();
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
	fSpace+= rhs.fSpace;
	fT+= rhs.fT;

	computeLength();
	return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs){
	fSpace-= rhs.fSpace;
	fT-= rhs.fT;

	computeLength();
	return *this;
}

FourVector& FourVector::operator=(const FourVector& rhs){
	if(&rhs==this) return *this;
	fSpace = rhs.fSpace;
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
