#include <iostream>

int main(){
	// This is a comment
	/* This is 
	   multiline comment */
	
	double a,b,c;
	char op;
	bool error;

	error = false;
	std::cout << "Hello world!" << std::endl;
	std::cout << "Please enter two numbers:" << std::endl;
	std::cin >> a;
	if(!std::cin){
		std::cout << "There was an error" << std::endl;
		error = true;
	}
	std::cin >> b;
	if(!std::cin){
		std::cout << "There was an error" << std::endl;
		error = true;
	}

	std::cout << "Please enter operation:" << std::endl;
	std::cin >> op;
	if(!std::cin){
		std::cout << "There was an error" << std::endl;
		error = true;
	}

	switch(op){
	case '/':
		if(b==0){
			std::cout << "Error division by 0" << std::endl;
			error=true;
			break;
		}
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

	if(!error){
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c=a" << op << "b is " << c << std::endl;
	}
	return 0;
}

