#include <iostream>
#include <string>

#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"
#include "day4.hpp"
#include "pp6menu.hpp"


static const int nTopMenu = 4;
static const std::string topMenu[nTopMenu] = {"1) Day 1", "2) Day 2", "3) Day 3", "4) Day 4"};

int main(){
	int selection;

	while(true){ //Infinite loop. Exit when user inputs chooses the exit option in the menu

		if(!printAndRequestTopMenu("Day 1 Menu: ", topMenu, nTopMenu, false, selection)) continue;

		switch(selection){
		case 1:
			if(executeday1()) return 0;
			break;
		case 2:
			if(executeday2()) return 0;
			break;
		case 3:
			if(executeday3()) return 0;
			break;
		case 4:
			if(executeday4()) return 0;
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

