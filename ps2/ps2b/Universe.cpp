#include "Universe.h"
#include <cmath>
#define G 6.674e-11

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

std::ostream& operator<< (std::ostream& out, Universe& uni){
	out << uni.getNumBodies() << std::endl;
	out << uni.getRadius() << std::endl;
	for(int i = 0; i < uni.getNumBodies(); i++){
		out << std::setw(14) << uni.getPlanet(i)->getXPos() << std::setw(14) << uni.getPlanet(i)->getYPos() 
		<< std::setw(14) << uni.getPlanet(i)->getXVelo() << std::setw(14) << uni.getPlanet(i)->getYVelo()
		<< std::setw(14) << uni.getPlanet(i)->getMass() << std::setw(20) << uni.getPlanet(i)->getFilename() << std::endl;
	}
	return out;
}


double Universe::getXDistance(CelestialBody& anchor, CelestialBody& source){
	return (source.getXPos() - anchor.getXPos());
}

double Universe::getYDistance(CelestialBody& anchor, CelestialBody& source){
	return (source.getYPos() - anchor.getYPos());
}

double Universe::getRDistance(CelestialBody& anchor, CelestialBody& source){
	double xDist, yDist, rDist;
	xDist = getXDistance(anchor, source);
	yDist = getYDistance(anchor, source);
	rDist = sqrt((xDist * xDist) + (yDist * yDist));
	return rDist;
}

double Universe::calcForce(CelestialBody& anchor, CelestialBody& source){
	double rDist = getRDistance(anchor, source);
	double force = ((G * ((anchor.getMass() * source.getMass())) / (rDist * rDist)));
	return force;
}

void Universe::step (double seconds){
	for (int i = 0; i < numCelestialBodies; i++){
		double accelX, accelY, uptXVelo = 0, uptYVelo = 0, force, xDist, yDist, rDist, mass;
		double initXVelo = getPlanet(i)->getXVelo(), initYVelo = getPlanet(i)->getYVelo(), forceX = 0, forceY = 0;
		mass = getPlanet(i)->getMass();
		for (int j = 0; j < numCelestialBodies; j++){
			if(j != i){
				force = calcForce(*getPlanet(i), *getPlanet(j));
				xDist = getXDistance(*getPlanet(i), *getPlanet(j));
				yDist = getYDistance(*getPlanet(i), *getPlanet(j));
				rDist = getRDistance(*getPlanet(i), *getPlanet(j));
				forceX += force * (xDist / rDist);
				forceY += force * (yDist / rDist);
			}
		}

		accelX = forceX / mass;
		accelY = forceY / mass;
		getPlanet(i)->setAccel(accelX, accelY);
		
		uptXVelo = initXVelo + (seconds * accelX);
		uptYVelo = initYVelo + (seconds * accelY);
		getPlanet(i)->setVelo(uptXVelo, uptYVelo);

	}
	for(int k = 0; k < numCelestialBodies; k++){
		double newXV, newYV;
		newXV = getPlanet(k)->getXPos() + (seconds * getPlanet(k)->getXVelo());
		newYV = getPlanet(k)->getYPos() + (seconds * getPlanet(k)->getYVelo());
		getPlanet(k)->setPosition(newXV, newYV);
	}
}