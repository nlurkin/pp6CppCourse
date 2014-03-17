#include <iostream>
#include <limits>

#include "pp6menu.hpp"

bool printAndRequestTopMenu(const std::string menuTitle, const std::string menu[], const int size, bool isSubMenu, int& select){
	int value;
	std::string menuOp;

	//Clear the input stream flags and values in case of error
	if(!std::cin){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << std::endl << menuTitle << std::endl;

	for(int i=0;i<size; ++i){
		std::cout <<"\t" << menu[i] << std::endl;
	}
	if(isSubMenu) std::cout <<"\t" << "-1) Go back one level" << std::endl;
	std::cout <<"\t" << "-2) Quit pp6calculator" << std::endl;

	std::cout << std::endl << "Please select an option: " << std::flush;
	std::cin >> value;
	if(!std::cin || value>size){
		std::cout << "[error] Your input is not a valid option" << std::endl;
		return false;
	}

	select = value;
	return true;
}

/**
 * Wait for a number in cin. Print an error message if the input is not a number.
 * Params: number
 * Return: true if input can be parsed as float
 */
bool inputNumber(float &number){
	std::cin >> number;
	if(!std::cin){
		std::cout << "There is a problem with your input" << std::endl;
		return false;
	}
	return true;
}

/**
 * Wait for a number in cin. Print an error message if the input is not a number.
 * Params: number
 * Return: true if input can be parsed as float
 */
bool inputNumber(double &number){
	std::cin >> number;
	if(!std::cin){
		std::cout << "There is a problem with your input" << std::endl;
		return false;
	}
	return true;
}

