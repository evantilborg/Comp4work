#include <iostream>
#include <string.h>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Universe.h"
#include "CelestialBody.h"

int main(int argc, const char * argv[]){

	double totalTime = std::stod(argv[1]);
	double secondsPerStep = std::stod(argv[2]);
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

	sf::Font font;
	if(!font.loadFromFile("comic_sans.ttf")){
		std::cout << "Could not open font file" << std::endl;
		return -1;
	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);

	sf::Music music;
	if(MilkyWay.getNumBodies() <= 5){
		if(!music.openFromFile("BigBang.wav")){
			return -1;
		}
	} else{
		if(!music.openFromFile("starwars.wav")){
			return -1;
		}	
	}

	music.setLoop(false);
	music.play();
	
	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Universe");
	double timeElapsed = 0;
	window.setFramerateLimit(60);
	while (window.isOpen()){
		sf::Event event;
		//while(totalTime > timeElapsed){
			while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed|| timeElapsed > totalTime){
					window.close();
				}
			}
			std::string Time = (std::to_string(timeElapsed));
			text.setString(Time);
			window.clear();
			window.draw(Backdrop);
			window.draw(text);
			
			for(int i = 0; i < MilkyWay.getNumBodies(); i++){
				window.draw(*MilkyWay.getPlanet(i));
			}
			//MilkyWay.printContents();
			window.display();
			MilkyWay.step(secondsPerStep);
			if(timeElapsed > totalTime){
				secondsPerStep = 0;
			}
			timeElapsed += secondsPerStep;
		//}
	}
	std::cout << MilkyWay;

	return 0;
}
