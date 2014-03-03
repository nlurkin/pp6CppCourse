#include <iostream>

int main(){
	// This is a comment
	/* This is 
	   multiline comment */
	
	double a,b,c;
	char op;

	std::cout << "Hello world!" << std::endl;
	std::cout << "Please enter two numbers:" << std::endl;
	std::cin >> a;
	if(!std::cin) std::cout << "There was an error" << std::endl;
	std::cin >> b;
	if(!std::cin) std::cout << "There was an error" << std::endl;

	std::cout << "Please enter operation:" << std::endl;
	std::cin >> op;
	if(!std::cin) std::cout << "There was an error" << std::endl;

	switch(op){
	case '/':
		c = a/b;
		break;
	case '*':
		c = a*b;
		break;
	case '+':
		c = a+b;
		break;
	case '-':
		c = a-b;
		break;
	}

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c=a" << op << "b is " << c << std::endl;
	return 0;
}

