#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Universe.h"
#include "CelestialBody.h"

int main(int argc, const char * argv[]){

	Universe MilkyWay;
	std::cin >> MilkyWay;

	int windowSizeX = 500, windowSizeY = 500;

	for(int i = 0; i < MilkyWay.getNumBodies(); i++){
		auto temp = MilkyWay.getPlanet(i);
		temp->setWindowDimensions(windowSizeX, windowSizeY);
		temp->setPosition(temp->getXPos(), temp->getYPos());
	}

	sf::Image backdropIMG;
	if(!backdropIMG.loadFromFile("starfield.jpg")){
		return -1;
	}

	sf::Texture backdropTEX;
	backdropTEX.loadFromImage(backdropIMG);
	backdropTEX.setRepeated(true);

	sf::Sprite Backdrop;
	Backdrop.setTexture(backdropTEX);

	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Universe");
	while (window.isOpen()){
		sf::Event event; 
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		window.draw(Backdrop);
		for(int i = 0; i < MilkyWay.getNumBodies(); i++){
			window.draw(*MilkyWay.getPlanet(i));
		}
		window.display();
	}
	return 0;
}
