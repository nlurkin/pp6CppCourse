#include <iostream>
#include <limits>
#include <string>

//TODO comment the code

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

bool intercept(float &c, float x[2], float y[2]){
	float m,p;
	if((y[1]-y[0])==0){
		std::cout << "Unable to compute intercept with x. Line is parallel to x axis." << std::endl;
		return false;
	}
	m = (y[1]-y[0])/(x[1]-x[0]);
	p = y[0]-m*x[0];
	c = -p/m;
	return true;
}

bool inputNumber(float &number){
	std::cin >> number;
   if(!std::cin){
		std::cout << "There is a problem with your input" << std::endl;
		return false;
	}
	return true;
}

int main(){
	// This is a comment
	/* This is 
	   multiline comment */
	
	float a,b;
	float x[2],y[2];
	float result;
	std::string op;

	std::cout << "Hello world!" << std::endl;

	while(true){
		if(!std::cin){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "Please enter operation (/,*,+,-,q):" << std::endl;
		std::cin >> op;
		if(!std::cin){
			std::cout << "There is an error with the operation you entered" << std::endl;
			continue;
		}

		if(op.compare("q")==0) break;

		if(op.length()==1){
			std::cout << "Please enter two numbers:" << std::endl;
			if(!inputNumber(a)) continue;
			if(!inputNumber(b)) continue;
		}
		else{
			std::cout << "Please enter four numbers (x1,y1,x2,y2):" << std::endl;
			if(!inputNumber(x[0])) continue;
			if(!inputNumber(y[0])) continue;
			if(!inputNumber(x[1])) continue;
			if(!inputNumber(y[1])) continue;
		}

		if(op.compare("/")==0){
			if(!div(result,a,b)) continue;
		}
		else if(op.compare("*")==0){
			if(!mul(result,a,b)) continue;
		}
		else if(op.compare("+")==0){
			if(!plus(result,a,b)) continue;
		}
		else if(op.compare("-")==0){
			if(!minus(result,a,b)) continue;
		}
		else if(op.compare("intercept")==0){
			if(!intercept(result, x, y)) continue;
		}
		else{
			std::cout << "Unknown operation " << op << std::endl;
			continue;
		}
	
		std::cout << "The result is " << result << std::endl;
	}
	return 0;
}

