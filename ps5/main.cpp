// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include "EDistance.h"
#include <SFML/System.hpp>

int main() {
    sf::Clock clock;
    sf::Time t;

    std::string str1, str2;
    std::cin >> str1;
    std::cin >> str2;

    EDistance ed(str1, str2);

    int optDist = ed.optDistance();
    std::string Alignment = ed.alignment();

    t = clock.getElapsedTime();

    std::cout << "Edit Distance = "  << optDist << std::endl;
    std::cout << Alignment << std::endl;
    std::cout << "Execution time is: " << t.asSeconds() << " seconds \n";

    return 0;
}
