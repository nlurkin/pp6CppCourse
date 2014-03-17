#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH
#include <iostream>
#include "Particle.hpp"

bool mul(float &c, float a, float b);
bool div(float &c, float a, float b);
bool add(float &c, float a, float b);
bool sub(float &c, float a, float b);
bool intercept(float &i, float x1, float y1, float x2, float y2);
bool quadSolve(float &x1, float &x2, float a, float b, float c);
bool magVector3(float &mag, float a, float b, float c);
bool magVector3(double &mag, double a, double b, double c);
bool magVector4(float &mag, float a, float b, float c, float d);
bool invMass(float &mass, float m1, float m2, float p1[3], float p2[3]);
bool invMass(double &mass, double m1, double m2, double p1[3], double p2[3]);
bool swap(double& a, double& b);
bool swap(int& a, int& b);
bool bubbleSort(int size, double *arr);
bool bubbleSort(int size, Particle **arr);
bool bubbleSortIndex(int size, double *arr, int *indArr);

bool isEq(float a, float b);
bool isEq(double a, double b);

bool flat(double& rnd, double min, double max);
bool gauss(double& rnd, double mu, double sigma);
bool generateEvent(Particle (&vP)[100], double mass, double sigma);

#endif 

