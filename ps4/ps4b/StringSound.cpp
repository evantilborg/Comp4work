// (C) Copyright Erik van Tilborg, 2022
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include "StringSound.h"

std::random_device device;
std::mt19937 generator(device());
std::uniform_int_distribution<int16_t> dist(SHRT_MIN, SHRT_MAX);

StringSound::StringSound(double frequency) {
    if (frequency <= 0) {
        throw std::invalid_argument
        ("The frequency MUST be a number greater than zero");
    } else {
        auto capacity = std::ceil(SAMPLING_RATE / frequency);
        _cb = new CircularBuffer(capacity);
        _time = 0;
    }
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    if (init.size() <= 0) {
        throw std::invalid_argument
        ("The initial value given must be greater than 0");
    } else {
        _cb = new CircularBuffer(init.size());
        _time = 0;
        for (auto i : init) {
            _cb->enqueue(i);
        }
    }
}

StringSound::~StringSound() {
    delete _cb;
}

void StringSound::pluck() {
    _cb->empty();
    while (_cb->isFull() == false) {
        _cb->enqueue(dist(generator));
    }
}

void StringSound::tic() {
    auto val1 = _cb->dequeue();
    auto val2 = _cb->peek();
    std::int16_t nextVal = _cb->getDecayVal() * 0.5 * (val1 + val2);
    _cb->enqueue(nextVal);
    _time++;
}

sf::Int16 StringSound::sample() {
    return _cb->peek();
}

int StringSound::time() {
    return _time;
}
