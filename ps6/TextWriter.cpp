// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include <iostream>
#include <string>
#include "RandWriter.h"

using std::cout;

template <typename T>
int convertCharToInt(const char * argument, T&& rickroll) {
    auto temp = rickroll;
    return temp(argument);
}

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        cout << "Usage is as follows: ./TextGenerator <int k> <int L>\n";
        return -1;
    }

    int k = convertCharToInt(argv[1], [&](auto temp){ return std::stoi(temp);});
    int L = convertCharToInt(argv[2], [&](auto temp){return std::stoi(temp);});


    std::string text;
    std::string input_text = "";
    std::string output_text = "";

    while (std::getline(std::cin, input_text)) {
        text.append(input_text);
        input_text = "";
    }

    cout << "Original Inputted Text:\n";
    for (int i = 0; i < text.length(); i++) {
        cout << text[i];
    }
    cout << std::endl;

    RandWriter rw(text, k);

    cout << rw << std::endl;

    output_text = rw.generate(text.substr(0, k), L);

    cout << "Generated Text:\n";
    for (int i = 0; i < L; i++) {
        cout << output_text[i];
    }
    cout << std::endl;

    // debugOutput(rw.getMap());

    return 0;
}
