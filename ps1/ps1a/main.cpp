/************************************************************
 *Name: <Erik van Tilborg>
 *Course name: <COMP.2040>
 *Assignment: <PS1a>
 *Instructor's name: <Dr. James Daly>
 *Date: <1/31/22>
 *Sources Of Help: <class notes>
************************************************************/
#include <iostream>
#include "FibLFSR.h"

int main(int argc, const char * argv[]){

	FibLFSR flfsr1("1011011000110110");
	int i = 0;

	while(i < 10){
		int x = flfsr1.step();
		std::cout << flfsr1 << " " << x << std::endl;
		i++;
	}

	std::cout << "\n";
	
	FibLFSR flfsr2("1011011000110110");
	int j = 0;
	while(j < 7){
		int y = flfsr2.generate(5);
		std::cout << flfsr2 << " " << y << std::endl;
		j++;
	}

	return 0;
}