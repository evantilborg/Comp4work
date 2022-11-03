// (C) Copyright Erik van Tilborg, 2022
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "StringSound.h"

std::vector<sf::Int16> makeSamples(StringSound* guitar) {
    std::vector<sf::Int16> samples;
    guitar->pluck();
    int duration = 8;
    int i;
    for (i= 0; i < SAMPLING_RATE * duration; i++) {
        guitar->tic();
        samples.push_back(guitar->sample());
    }
    return samples;
}

int main() {
  std::vector<std::vector<sf::Int16>> soundSamples;
  std::vector<sf::SoundBuffer> soundBuf(size_of_keyboard);
  std::vector<sf::Sound> sound(size_of_keyboard);

  soundSamples.reserve(size_of_keyboard);

  auto getRespectiveFrequency = [](auto i) {
      return 440 * pow(2, ((i - 24) / 12));
  };

  for (int i = 0; i < size_of_keyboard; i++) {
      StringSound freq(getRespectiveFrequency(i));
      soundSamples[i] = makeSamples(&freq);
      if (!soundBuf[i].loadFromSamples
      (&soundSamples[i][0], soundSamples[i].size(), 2, SAMPLING_RATE)) {
          throw std::runtime_error("sf::SoundBuffer: Failed to load");
      }
      sound[i].setBuffer(soundBuf[i]);
  }

  sf::RenderWindow window(sf::VideoMode(300, 300), "SFML Guitar Sim");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
          window.close();
      }
      if (event.type == sf::Event::TextEntered) {
        for (int i = 0; i < size_of_keyboard; i++) {
          if (static_cast<unsigned>(event.text.unicode) == keyboard_keys[i]) {
            std::cout << "Current Note: " << keyboard_keys[i] << std::endl;
            sound[i].play();
          }
        }
      }
      window.clear();
      window.display();
    }
  }
  return 0;
}
