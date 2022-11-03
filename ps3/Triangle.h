// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Triangle: public sf::Drawable {
 public:
    Triangle(double base, sf::Vector2<double> center,
    sf::PrimitiveType = sf::LineStrip);

 private:
    std::shared_ptr<sf::VertexArray> verticies;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {  //NOLINT
        target.draw(*verticies, states);
    }
};
