// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include <iostream>
#include <cmath>
#include "Triangle.h"

Triangle::Triangle(double base, sf::Vector2<double> cPoint,
sf::PrimitiveType type) {
    double Alt = base * (sqrt(3) / 2);
    verticies = std::make_shared<sf::VertexArray>(sf::LinesStrip, 4);

    (*verticies)[0].position =
    sf::Vector2f(cPoint.x - (base / 2.0), cPoint.y - (Alt / 2.0));

    (*verticies)[1].position =
    sf::Vector2f(cPoint.x + (base / 2.0), cPoint.y - (Alt / 2.0));

    (*verticies)[2].position =
    sf::Vector2f(cPoint.x, cPoint.y + (Alt / 2.0));

    (*verticies)[3] = (*verticies)[0];
}
