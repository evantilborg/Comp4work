#pragma once

#include <iostream>
#include <memory>
#include "CelestialBody.h"

class Universe {
public:
	Universe() = default;

	int getSize(){
		return universeContents.size();
	}

	double getRadius() const {
		return uniRadius;
	}

	int getNumBodies() const {
		return numCelestialBodies;
	}

	std::shared_ptr<CelestialBody> getPlanet(int x){
		return universeContents[x];
	}
	
	void printContents();

	friend std::istream& operator>> (std::istream& in, Universe& uni);

private:
	int numCelestialBodies;
	double uniRadius;
	std::vector<std::shared_ptr<CelestialBody> > universeContents;
};
