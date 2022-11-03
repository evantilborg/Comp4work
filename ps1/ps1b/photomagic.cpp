#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

void transform(sf::Image& img, FibLFSR* obj);

int main(int argc, const char* argv[]){

	if(argc < 4){
		std::cout << "Too Few Arguments: Requires 4 arguments" << std::endl;
		exit(1);
	}

	sf::Image img_in, img_out;

	FibLFSR lfsr(argv[3]);

	if(!img_in.loadFromFile(argv[1])){
		return -1;
	}

	img_out = img_in;

	transform(img_out, &lfsr);

	sf::Vector2u size = img_in.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output");

	sf::Texture texture_in;
	texture_in.loadFromImage(img_in);

	sf::Texture texture_out;
	texture_out.loadFromImage(img_out);

	sf::Sprite sprite_in;
	sprite_in.setTexture(texture_in);	

	sf::Sprite sprite_out;
	sprite_out.setTexture(texture_out);

	while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window1.pollEvent(event)) {
			if (event.type == sf::Event::Closed){
				window1.close();
			}
		}

		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed){
				window2.close();
			}
		}

		window1.clear(sf::Color::White);
		window1.draw(sprite_in);
		window1.display();
		window2.clear(sf::Color::White);
		window2.draw(sprite_out);
		window2.display();
	}

	if (!img_out.saveToFile(argv[2])){
		return -1;
	}

	return 0;
}

void transform(sf::Image& img, FibLFSR* obj){
	sf::Color pixel;
	for(size_t x = 0; x < img.getSize().x; x++){
		for(size_t y = 0; y < img.getSize().y; y++){
			pixel = img.getPixel(x,y);
			pixel.r = pixel.r ^ obj->generate(8);
			pixel.g = pixel.g ^ obj->generate(8);
			pixel.b = pixel.b ^ obj->generate(8);
			img.setPixel(x, y, pixel);
		}
	}
}
