// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include "RandWriter.h"
#include <iterator>
#include <vector>

RandWriter::RandWriter(std::string text, int k) : _order(k) {
    int lengthOfText = text.size();
    char temp;
    bool alpha = false;
    std::string copyText = text;

    for (int i = 0; i < _order; i++) {
        copyText.push_back(text[i]);
    }

    for (int i = 0; i < lengthOfText; i++) {
        temp = text.at(i);
        alpha = false;
        for (unsigned int j = 0; j < Alphabet.length(); j++) {
            if (Alphabet.at(j) == temp) {
                alpha = true;
            }
        }
        if (!alpha) {
            Alphabet.push_back(temp);
        }
    }

    std::sort(Alphabet.begin(), Alphabet.end());
    std::string subStr;
    char nextChar;

    for (int j = 0; j < text.length(); j++) {
        nextChar = copyText.at(j + _order);
        subStr = copyText.substr(j, _order);
        kGramMap[subStr].freq++;
        kGramMap[subStr].charFreq[nextChar];
        kGramMap[subStr].charFreq[nextChar]++;
    }

    srand((int)time(NULL));  //NOLINT
}

int RandWriter::orderK() const {
    return _order;
}

int RandWriter::freq(std::string kgram) const {
    if (kgram.length() != _order) {
        throw std::runtime_error("ERROR: kGram not of length k");
    }

    std::map<std::string, kGramInfo>::const_iterator iter;
    iter = kGramMap.find(kgram);
    if (iter == kGramMap.end()) {
        return 0;
    }
    return kGramMap.at(kgram).freq;
}

int RandWriter::freq(std::string kgram, char c) const {
    if (kgram.length() != _order) {
        throw std::runtime_error("ERROR: kGram not of length k");
    }

    std::map<std::string, kGramInfo>::const_iterator iter;
    iter = kGramMap.find(kgram);
    if (iter == kGramMap.end()) {
        return 0;
    }
    return kGramMap.at(kgram).charFreq.at(c);
}

char RandWriter::kRand(std::string kgram) {
    if (kgram.length() != _order) {
        throw std::runtime_error("ERROR: kgram is not of length k");
    }

    std::map<std::string, kGramInfo>::iterator iter;
    std::map<char, int>::iterator iter2;

    iter = kGramMap.find(kgram);

    if (iter == kGramMap.end()) {
        throw std::runtime_error("Inputted kGram does not exist");
    }

    std::vector<char> randData;

    for (iter2 = iter->second.charFreq.begin();
         iter2 != iter->second.charFreq.end(); iter2++) {
        for (int i = 0; i < iter2->second; i++) {
            randData.push_back(iter2->first);
        }
    }

    int randVal = (rand() % randData.size());  //NOLINT

    return randData[randVal];
}

std::string RandWriter::generate(std::string kgram, int L) {
    if (kgram.length() != _order) {
        throw std::runtime_error("ERROR: kgram is not of length k");
    }
    if (L <= _order) {
        throw std::runtime_error("ERROR: L must be greater >= to k");
    }
    std::string returnStr = kgram;
    char returnChar;

    for (int i = 0; i < (L - _order); i++) {
        returnChar = kRand(returnStr.substr(i, _order));
        returnStr.push_back(returnChar);
    }

    return returnStr;
}

std::ostream &operator<<(std::ostream &out, RandWriter &obj) {
    out << "Order: " << obj.orderK() << std::endl;
    out << "Alphabet: " << obj.Alphabet << std::endl;
    std::map<std::string, kGramInfo>::iterator KIter;
    std::map<char, int>::iterator CFIter;
    for (KIter = obj.kGramMap.begin(); KIter != obj.kGramMap.end(); KIter++) {
        for (CFIter = KIter->second.charFreq.begin();
             CFIter != KIter->second.charFreq.end(); CFIter++) {
            out << "KGram: " << KIter->first << " Frequency: "
            << KIter->second.freq << " Next Char: " << CFIter->first
            << " Frequency: " << CFIter->second << std::endl;
        }
    }
    return out;
}
