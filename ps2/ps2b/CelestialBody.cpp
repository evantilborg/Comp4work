#include <iostream>
#include <string>
#include "CelestialBody.h"

CelestialBody::CelestialBody(double x, double y, double xVelo, double yVelo, double mass, const std::string& planetName){
	xPos = x;
	yPos = y;
	xVelocity = xVelo;
	yVelocity = yVelo;
	Mass = mass;
	PlanetName = planetName;
	//setPos(xPos, yPos);
	if(!planetIMG.loadFromFile(planetName)){
		std::cout << "Could not load file" << std::endl;
	}
	planetTEX.loadFromImage(planetIMG);
	Planet.setTexture(planetTEX);
}

void CelestialBody::setPosition (double x, double y){
	xPos = x;
	yPos = y;
	double viewportX = (x / radius) * (windowX / 2) + (windowX / 2);
	double viewportY = (-y / radius) * (windowY / 2) + (windowY / 2);
	double viewXPos = viewportX;
	double viewYPos = viewportY;
	Planet.setOrigin(Planet.getTexture()->getSize().x /2, Planet.getTexture()->getSize().y /2);
	Planet.setPosition(viewXPos, viewYPos);
}
