#include <iostream>
#include <limits>

int main(){
	// This is a comment
	/* This is 
	   multiline comment */
	
	double a,b,c;
	char op;
	double quit;

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
			std::cout << "There was an error" << std::endl;
			continue;
		}
		std::cin >> b;
		if(!std::cin){
			std::cout << "There was an error" << std::endl;
			continue;
		}

		std::cout << "Please enter operation:" << std::endl;
		std::cin >> op;
		if(!std::cin){
			std::cout << "There was an error" << std::endl;
			continue;
		}

		switch(op){
		case '/':
			if(b==0){
				std::cout << "Error division by 0" << std::endl;
				continue;
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
		case 'q':
			quit=true;
			continue;
		default:
			std::cout << "Uknown operation " << op << std::endl;
			continue;
		}
	
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c=a" << op << "b is " << c << std::endl;
	}
	return 0;
}

