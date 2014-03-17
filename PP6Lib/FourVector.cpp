#include "FourVector.hpp"
#include <math.h>

/**
 * Constructor setting the 4 components
 * Params: x,y,z: Space components
 *         t: Time component
 */
FourVector::FourVector(double x, double y, double z, double t):
fSpace(x,y,z),fT(t)
{
	computeLength();
}

/**
 * Change the value of the 4 components
 * Params: x,y,z: Space components
 *         t: Time component
 */
void FourVector::setXYZT(double x, double y, double z, double t){
	fSpace.setXYZ(x,y,z);
	fT = celerity*t;

	computeLength();
}

/**
 * Boost the 4-vector along z
 * Params: v: Speed of the boost along z
 */
void FourVector::boostZ(double v){
	double beta = v/celerity;
	double gamma = 1./sqrt(1.-beta*beta);
	double ct = fT;
	double z;

	fT = gamma*(ct-beta*fSpace.getZ());
	z = gamma*(fSpace.getZ()-beta*ct);
	fSpace.setXYZ(fSpace.getX(), fSpace.getY(), z);
}

/**
 * Compute the length of the 4-vector (with metric +---)
 */
void FourVector::computeLength(){
	double lSquare = fT*fT - fSpace.getLength();
	if(lSquare<0) fLength = -sqrt(-lSquare);
	else fLength = sqrt(lSquare);
}

/**
 * Get the type of the 4-vector:
 * Return: Causal type
 * 	SpaceLike: ||V||<0 (kSPACELIKE)
 * 	TimeLike:  ||V||>0 (kTIMELIKE)
 * 	Null:      ||V||=0 (kNULL)
 */
FourVector::CausalType FourVector::getType() const{
	if(fLength<0) return kSPACELIKE;
	if(fLength>0) return kTIMELIKE;
	else return kNULL;
}

/**
 * Get the time component.
 * Return: Time component of the vector
 */
double FourVector::getT() const{
	return fT/celerity;
}

/**
 * Output the vector components to the output stream.
 * Params: stream: Output stream
 *         v: 4-vector to print
 * Return: Reference to the output stream
 */
std::ostream& operator<<(std::ostream& stream, const FourVector& v){
	stream << "(" << v.getT() << "," << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
	return stream;
}

/**
 * Fill a 4-vector components from input stream.
 * Params: stream: Input stream
 *         v: 4-vector to fill
 * Return: Reference to input stream
 */
std::istream& operator>>(std::istream& stream, FourVector& v){
	double x,y,z,t;
	stream >> x >> y >> z >> t;
	v.setXYZT(x,y,z,t);
	return stream;
}

/**
 * Assignment addition of 4-vectors.
 * Params: rhs: 4-vector to add to the current 4-vector
 * Return: Reference to this vector.
 */
FourVector& FourVector::operator+=(const FourVector& rhs){
	fSpace+= rhs.fSpace;
	fT+= rhs.fT;

	computeLength();
	return *this;
}

/**
 * Assignment substraction of 4-vectors.
 * Params: rhs: 4-vector to substract to the current 4-vector
 * Return: Reference to this vector.
 */
FourVector& FourVector::operator-=(const FourVector& rhs){
	fSpace-= rhs.fSpace;
	fT-= rhs.fT;

	computeLength();
	return *this;
}

/**
 * Assignment operator.
 * Params: rhs: 4-vector replacing the current 4-vector
 * Return: Reference to this 4-vector
 */
FourVector& FourVector::operator=(const FourVector& rhs){
	if(&rhs==this) return *this;
	fSpace = rhs.fSpace;
	fT = rhs.fT;
	fLength = rhs.fLength;
	return *this;
}

/**
 * Addition of 4-vectors.
 * Params: lhs,rhs: 4-vectors to add
 * Return: New 4-vector
 */
FourVector operator+(const FourVector& lhs, const FourVector& rhs){
	FourVector r(lhs);
	r+= rhs;
	return r;
}

/**
 * Substraction of 4-vectors.
 * Params: lhs,rhs: 4-vectors to substract
 * Return: New 4-vector
 */
FourVector operator-(const FourVector& lhs, const FourVector& rhs){
	FourVector r(lhs);
	r-= rhs;
	return r;
}
