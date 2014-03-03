#include <iostream>
#include <limits>

bool mul(float &c, float a, float b){
	c = a*b;
	return true;
}
bool div(float &c, float a, float b){
	if(b==0){
		std::cout << "Error division by 0" << std::endl;
		return false;
	}
	c = a/b;
	return true;
}
bool plus(float &c, float a, float b){
	c = a+b;
	return true;
}
bool minus(float &c, float a, float b){
	c = a-b;
	return true;
}

int main(){
	// This is a comment
	/* This is 
	   multiline comment */
	
	float a,b,c;
	char op;
	bool quit;

	quit = false;
	while(!quit){
		if(!std::cin){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "Hello world!" << std::endl;
		std::cout << "Please enter two numbers:" << std::endl;
		std::cin >> a;
		if(!std::cin){
			std::cout << "There is a problem with your input" << std::endl;
			continue;
		}
		std::cin >> b;
		if(!std::cin){
			std::cout << "There is a problem with your input" << std::endl;
			continue;
		}

		std::cout << "Please enter operation (/,*,+,-,q):" << std::endl;
		std::cin >> op;
		if(!std::cin){
			std::cout << "There is an error with the operation you entered" << std::endl;
			continue;
		}

		switch(op){
		case '/':
			if(!div(c,a,b)) continue;
			break;
		case '*':
			if(!mul(c,a,b)) continue;
			break;
		case '+':
			if(!plus(c,a,b)) continue;
			break;
		case '-':
			if(!minus(c,a,b)) continue;
			break;
		case 'q':
			quit=true;
			continue;
		default:
			std::cout << "Unknown operation " << op << std::endl;
			continue;
		}
	
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c=a" << op << "b is " << c << std::endl;
	}
	return 0;
}

