#ifndef PP6CALCULATOR_PP6MENU_HH
#define PP6CALCULATOR_PP6MENU_HH

#include <string>
#include "quadVector.hpp"

bool printAndRequestTopMenu(const std::string menuTitle, const std::string menu[], const int size, bool isSubMenu, int& select);
bool inputNumber(float &number);
bool inputNumber(double &number);
bool inputQuadVector(QuadVector &v);

#endif
