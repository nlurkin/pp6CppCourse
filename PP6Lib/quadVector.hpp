//Do consts where applicable
//Do trinity

#ifndef QUADVECTOR_HPP
#define QUADVECTOR_HPP
#include <iostream>

extern const double celerity;

class QuadVector{
public:
	enum CausalType {kSPACELIKE, kTIMELIKE, kNULL};

	QuadVector():fX(0),fY(0),fZ(0),fT(0){};
	QuadVector(double x, double y, double z, double t);
	QuadVector(const QuadVector& v):fX(v.fX),fY(v.fY),fZ(v.fZ),fT(v.fT),fLength(v.fLength){};

	~QuadVector(){};
	
	void setXYZT(double x, double y, double z, double t);
	void boostZ(double v);
	double getLength() const{ return fLength;};
	CausalType getType() const;

	double getX() const { return fX;};
	double getY() const { return fY;};
	double getZ() const { return fZ;};
	double getT() const;

	QuadVector& operator+=(const QuadVector& rhs);
	QuadVector& operator-=(const QuadVector& rhs);
	QuadVector& operator=(const QuadVector& rhs);
private:
	void computeLength();

	double fX,fY,fZ,fT;
	double fLength;
};

std::ostream& operator<<(std::ostream& stream, const QuadVector& v);
std::istream& operator>>(std::istream& stream, QuadVector& v);

QuadVector operator+(const QuadVector& v1, const QuadVector& v2);
QuadVector operator-(const QuadVector& v1, const QuadVector& v2);
#endif
