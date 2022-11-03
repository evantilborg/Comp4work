// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Triangle.h"

void fTree(std::vector<Triangle> *triangleHouse, sf::Vector2<double>
centerPoint, double base, int recur, sf::PrimitiveType type);

int main(int argc, const char* argv[]) {
    double windowSize = 500, baseLength = std::stod(argv[1]);
    int recursions = std::stoi(argv[2]);

    if (baseLength > windowSize / 2) {
        windowSize *= 4;
    }

    sf::Vector2<double> centerPoint;
    centerPoint.x = (windowSize / 2);
    centerPoint.y = (windowSize / 2);

    std::vector<Triangle> triangleStorage;
    fTree(&triangleStorage, sf::Vector2<double>
    (0.5 * windowSize, 0.5 * windowSize), baseLength, recursions,
    sf::LineStrip);

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize),
    "Recursive Graphics");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Blue);
        for (int i = 0; i < triangleStorage.size(); i++) {
            window.draw(triangleStorage[i]);
        }
        window.display();
    }
    return 0;
}

void fTree(std::vector<Triangle> *triangleHouse, sf::Vector2<double>
centerPoint, double base, int recur, sf::PrimitiveType type) {
    if (recur < 0) {  // If number of recursions is negative, return
        return;
    }

    if (base < 0) {  // If base is negative, set equal to 0
        base = 0;
    }
    // Push current triangle into the vector for drawing
    triangleHouse->push_back(Triangle(base, centerPoint, sf::LineStrip));

    double Height = base * (sqrt(3) / 2);  // calculate Altitude

    // Set VertexA
    sf::Vector2<double> VertexA {(centerPoint.x - (0.5 * base)),
    (centerPoint.y - (0.75 * Height))};
    // Set VertexB
    sf::Vector2<double> VertexB {(centerPoint.x + (0.75 * base)),
    (centerPoint.y - (0.25 * Height))};
    // Set VertexC
    sf::Vector2<double> VertexC {(centerPoint.x - (0.25 * base)),
    (centerPoint.y + (0.75 * Height))};

    // recursive call for VertexA
    fTree(triangleHouse, VertexA, (base / 2.0), (recur - 1), type);
    // recursive call for VertexB
    fTree(triangleHouse, VertexB, (base / 2.0), (recur - 1), type);
    // recursive call for VertexC
    fTree(triangleHouse, VertexC, (base / 2.0), (recur - 1), type);
}
