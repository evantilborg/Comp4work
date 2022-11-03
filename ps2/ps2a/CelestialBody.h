#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {

public:
CelestialBody(double x, double y, double xVelo, double yVelo, double mass, const std::string& planetName);

double getXPos() const {
	return xPos;
}

double getYPos() const {
	return yPos;
}

double getXVelo() const {
	return xVelocity;
}

double getYVelo() const {
	return yVelocity;
}

double getMass() const {
	return Mass;
}

void setRadius(double rad){
	radius = rad;
}

void setPosition(double x, double y);

void setWindowDimensions(int width, int depth){
	windowX = width;
	windowY = depth;
}

void setViewportCoords();

private:
	int windowX, windowY;
	double xPos, yPos, xVelocity, yVelocity, Mass, radius;
	std::string PlanetName;
	sf::Image planetIMG;
	sf::Texture planetTEX;
	sf::Sprite Planet;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		target.draw(Planet, states);
	}
};
