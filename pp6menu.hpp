#ifndef PP6CALCULATOR_PP6MENU_HH
#define PP6CALCULATOR_PP6MENU_HH

#include <string>

extern int nd2Menu;
extern std::string d2Menu[];

bool printAndRequestTopMenu(const std::string menuTitle, const std::string menu[], const int size, bool isSubMenu, int& select);
bool inputNumber(float &number);

#endif
