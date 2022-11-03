#pragma once
#include <iostream>
#include <iomanip>
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

	void step (double seconds);
	double calcForce(CelestialBody& anchor, CelestialBody& source);
	double getXDistance(CelestialBody& anchor, CelestialBody& source);
	double getYDistance(CelestialBody& anchor, CelestialBody& source);
	double getRDistance(CelestialBody& anchor, CelestialBody& source);
	

	//sf::Vector2f normalize(const sf::Vector2f& vec);
	//double getMagnitude(const sf::Vector2f& vec);

	friend std::istream& operator>> (std::istream& in, Universe& uni);
	friend std::ostream& operator<< (std::ostream& out, Universe& uni);

private:
	int numCelestialBodies;
	double uniRadius;
	std::vector<std::shared_ptr<CelestialBody> > universeContents;
};
