/************************************************************
 *Name: <Erik van Tilborg>
 *Course name: <COMP.2040>
 *Assignment: <PS0>
 *Instructor's name: <Dr. James Daly>
 *Date: (Completed 1/24/22) Updated: <1/25/22>
 *Sources Of Help: <assignment handout and provided links>
 *Purpose: To set up the sfml tools for use in the semester
		   and to get familiar with some features
************************************************************/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works");
	window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	// Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
	// Set sprite position
	sprite.move(sf::Vector2f(500.f, 0.f));
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
		// Draw the circle
		window.draw(shape);
        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            sprite.move(0, -0.5);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            sprite.move(-0.5, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            sprite.move(0, 0.5);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            sprite.move(0.5, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            sprite.rotate(15);
        }
    }
    return EXIT_SUCCESS;
}