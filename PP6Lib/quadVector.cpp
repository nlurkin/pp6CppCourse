#include "quadVector.hpp"
#include <math.h>

QuadVector::QuadVector(double x, double y, double z, double t):
fX(x),fY(y),fZ(z),fT(t)
{
	computeLength();
}

void QuadVector::setXYZT(double x, double y, double z, double t){
	fX = x;
	fY = y;
	fZ = z;
	fT = celerity*t;

	computeLength();
}

void QuadVector::boostZ(double v){
	double beta = v/celerity;
	double gamma = 1./sqrt(1.-beta*beta);
	double ct = fT;
	fT = gamma*(ct-beta*fZ);
	fZ = gamma*(fZ-beta*ct);
}

void QuadVector::computeLength(){
	double lSquare = fT*fT - fX*fX - fY*fY - fZ*fZ;
	if(lSquare<0) fLength = -sqrt(-lSquare);
	else fLength = sqrt(lSquare);
}

QuadVector::CausalType QuadVector::getType() const{
	if(fLength<0) return kSPACELIKE;
	if(fLength>0) return kTIMELIKE;
	else return kNULL;
}

double QuadVector::getT() const{
	return fT/celerity;
}

std::ostream& operator<<(std::ostream& stream, const QuadVector& v){
	stream << "(" << v.getT() << "," << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
	return stream;
}

std::istream& operator>>(std::istream& stream, QuadVector& v){
	double x,y,z,t;
	stream >> x >> y >> z >> t;
	v.setXYZT(x,y,z,t);
	return stream;
}
