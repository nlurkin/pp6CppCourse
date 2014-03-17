#include "ThreeVector.hpp"
#include <math.h>

/**
 * Constructor setting the 4 components
 * Params: x,y,z: Space components
 */
ThreeVector::ThreeVector(double x, double y, double z):
fX(x),fY(y),fZ(z)
{
	computeLength();
}

/**
 * Change the value of the 3 components
 * Params: x,y,z: Space components
 */
void ThreeVector::setXYZ(double x, double y, double z){
	fX = x;
	fY = y;
	fZ = z;

	computeLength();
}

/**
 * Compute the length of the 3-vector
 */
void ThreeVector::computeLength(){
	double lSquare = fX*fX + fY*fY + fZ*fZ;
	fLength = sqrt(lSquare);
}

/**
 * Output the vector components to the output stream.
 * Params: stream: Output stream
 *         v: 4-vector to print
 * Return: Reference to the output stream
 */
std::ostream& operator<<(std::ostream& stream, const ThreeVector& v){
	stream << "(" << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
	return stream;
}

/**
 * Fill a 4-vector components from input stream.
 * Params: stream: Input stream
 *         v: 4-vector to fill
 * Return: Reference to input stream
 */
std::istream& operator>>(std::istream& stream, ThreeVector& v){
	double x,y,z;
	stream >> x >> y >> z;
	v.setXYZ(x,y,z);
	return stream;
}

/**
 * Assignment addition of 4-vectors.
 * Params: rhs: 4-vector to add to the current 4-vector
 * Return: Reference to this vector.
 */
ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs){
	fX+= rhs.fX;
	fY+= rhs.fY;
	fZ+= rhs.fZ;

	computeLength();
	return *this;
}

/**
 * Assignment substraction of 4-vectors.
 * Params: rhs: 4-vector to substract to the current 4-vector
 * Return: Reference to this vector.
 */
ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs){
	fX-= rhs.fX;
	fY-= rhs.fY;
	fZ-= rhs.fZ;

	computeLength();
	return *this;
}

/**
 * Assignment operator.
 * Params: rhs: 4-vector replacing the current 4-vector
 * Return: Reference to this 4-vector
 */

ThreeVector& ThreeVector::operator=(const ThreeVector& rhs){
	if(&rhs==this) return *this;
	fX = rhs.fX;
	fY = rhs.fY;
	fZ = rhs.fZ;
	fLength = rhs.fLength;
	return *this;
}

/**
 * Addition of 4-vectors.
 * Params: lhs,rhs: 4-vectors to add
 * Return: New 4-vector
 */
ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs){
	ThreeVector r(lhs);
	r+= rhs;
	return r;
}

/**
 * Substraction of 4-vectors.
 * Params: lhs,rhs: 4-vectors to substract
 * Return: New 4-vector
 */
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs){
	ThreeVector r(lhs);
	r-= rhs;
	return r;
}
