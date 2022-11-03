#include "Universe.h"

std::istream& operator>> (std::istream& in, Universe& uni){
	double x, y, xVelo, yVelo, mass; 
	std::string planetName;
	in >> uni.numCelestialBodies;
	in >> uni.uniRadius;
	int i = 0;
	while(i < uni.numCelestialBodies){
		in >> x >> y >> xVelo >> yVelo >> mass >> planetName;
		auto temp = std::make_shared<CelestialBody>(x, y, xVelo, yVelo, mass, planetName);
		temp->setRadius(uni.uniRadius);
		uni.universeContents.push_back(temp);
		i++;
	}

	return in;
}

//helper to verify that universe calculations were in line with what they should be.
void Universe::printContents(){
	std::cout << numCelestialBodies << std::endl;
	std::cout << uniRadius << std::endl;
	for(int i = 0; i < numCelestialBodies; i++){
		std::cout << universeContents[i]->getXPos() << " " << universeContents[i]->getYPos() << " "
		<< universeContents[i]->getXVelo() << " " << universeContents[i]->getYVelo() << " "
		<< universeContents[i]->getMass() << std::endl;	
	}
}
