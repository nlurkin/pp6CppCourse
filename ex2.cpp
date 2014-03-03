#include <iostream>

int main(){
	// This is a comment
	/* This is 
	   multiline comment */
	
	double a,b,c;

	std::cout << "Hello world!" << std::endl;
	std::cout << "Please enter two numbers:" << std::endl;
	std::cin >> a >> b;

	c = a*b;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c=a*b is " << c << std::endl;
	return 0;
}

