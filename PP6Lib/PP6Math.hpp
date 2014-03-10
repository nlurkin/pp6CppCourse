#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

bool mul(float &c, float a, float b);
bool div(float &c, float a, float b);
bool add(float &c, float a, float b);
bool sub(float &c, float a, float b);
bool intercept(float &i, float x1, float y1, float x2, float y2);
bool quadSolve(float (&x)[2], float a, float b, float c);
bool magVector3(float &mag, float a, float b, float c);
bool magVector3(double &mag, double a, double b, double c);
bool magVector4(float &mag, float a, float b, float c, float d);
bool invMass(float &mass, float m1, float m2, float p1[3], float p2[3]);
bool swap(double& a, double& b);
bool bubbleSort(int size, double* arr);
bool bubbleSortIndex(int size, double* arr, double *indArr);

bool isEq(float a, float b);
bool isEq(double a, double b);

bool flat(double& rnd, double min, double max);
bool gauss(double& rnd, double mu, double sigma);
bool generateEvent(double *vMass, double *vPx, double *vPy, double *vPz, double *vE,double mass, double sigma);
#endif 
