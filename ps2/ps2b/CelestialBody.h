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

sf::Vector2f getPos() const {
	return sf::Vector2f (xPos, yPos);
}

double getXVelo() const {
	return xVelocity;
}

double getYVelo() const {
	return yVelocity;
}

void setVelo(double x, double y){
	xVelocity = x;
	yVelocity = y;
}

double getMass() const {
	return Mass;
}

void setRadius(double rad){
	radius = rad;
}

void setForce(double F){
	force = F;
}

double getForce() const {
	return force;
}

void setAccel(double accX, double accY){
	accelX = accX;
	accelY = accY;
}

double getAccelX() const {
	return accelX;
}

double getAccelY() const {
	return accelY;
}

void setPosition(double x, double y);

void setWindowDimensions(int width, int depth){
	windowX = width;
	windowY = depth;
}

std::string getFilename() const{
	return PlanetName;
}

void setViewportCoords();

private:
	int windowX, windowY;
	double xPos, yPos, xVelocity, yVelocity, Mass, radius, force, accelX, accelY;
	std::string PlanetName;
	sf::Image planetIMG;
	sf::Texture planetTEX;
	sf::Sprite Planet;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		target.draw(Planet, states);
	}
};
