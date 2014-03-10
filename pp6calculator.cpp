#include <iostream>
#include <string>

#include "day1.hpp"
#include "pp6menu.hpp"


static const int nTopMenu = 2;
static const std::string topMenu[nTopMenu] = {"1) Day 1", "2) Day 2"};

int main(){
	int selection;

	while(true){ //Infinite loop. Exit when user inputs chooses the exit option in the menu

		if(!printAndRequestTopMenu("Day 1 Menu: ", topMenu, nTopMenu, false, selection)) continue;

		switch(selection){
		case 1:
			if(executeday1()) return 0;
			break;
		case -2:
			return true;
			break;
		default:
			std::cout << "Unknown operation " << selection << std::endl;
			continue;
			break;
		}
	}
	return 0;
}

