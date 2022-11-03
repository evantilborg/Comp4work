// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include "EDistance.h"
#include <string.h>
#include <iomanip>  // used in conjunction with debugging matrix output

const int MATCH = 0;
const int MISMATCH = 1;
const int GAP = 2;

EDistance::EDistance(const std::string strA, const std::string strB) :
                     A_str(strA), B_str(strB), mtx(A_str.size() + 1,
                     std::vector<int>(B_str.size() + 1, 0)) {
    int emuMult2 = 0;
    for (int i = strB.size(); i >= 0 ; i--) {
        mtx[strA.size()][i] = emuMult2;
        emuMult2 += 2;
    }

    emuMult2 = 0;
    for (int j = strA.size(); j >= 0; j--) {
        mtx[j][strB.size()] = emuMult2;
        emuMult2 += 2;
    }
}

int EDistance::penalty(char a, char b) {
    return (a == b) ? MATCH : MISMATCH;  // ternary op condenses if-else block
}

int EDistance::min(int a, int b, int c) {  //NOLINT
    if (a <= b && a <= c) {            // check one condition
        return a;
    } else {  // use of ternary op cuts down on if-else counts to check final 2
        return (b <= c) ? b : c;
    }
}

int EDistance::optDistance() {
    for (int i = A_str.size() - 1; i >= 0; i--) {
        for (int j = B_str.size() - 1; j >= 0; j--) {
            mtx[i][j] = min(mtx[i + 1][ j+ 1] + penalty(A_str[i], B_str[j]),  //NOLINT
            mtx[i + 1][j] + GAP, mtx[i][j + 1] + GAP);  //NOLINT
        }
    }
    return mtx[0][0];
}

std::string EDistance::alignment() {
    unsigned int i = 0, j = 0;
    std::string retString;
    while (i < A_str.size() && j < B_str.size()) {
        if (mtx[i][j] == mtx[i + 1][j + 1] + penalty(A_str[i], B_str[j])) {
            retString.push_back(A_str[i]);
            retString.push_back(' ');
            retString.push_back(B_str[j]);
            retString.push_back(' ');
            retString.push_back((penalty(A_str[i], B_str[j])) + '0');
            retString.push_back('\n');
            i++;
            j++;
        } else if (mtx[i][j] == mtx[i + 1][j] + GAP) {
            retString.push_back(A_str[i]);
            retString.push_back(' ');
            retString.push_back('-');
            retString.push_back(' ');
            retString.push_back(GAP + '0');
            retString.push_back('\n');
            i++;
        } else if (mtx[i][j] == mtx[i][j + 1] + GAP) {
            retString.push_back('-');
            retString.push_back(' ');
            retString.push_back(B_str[j]);
            retString.push_back(' ');
            retString.push_back(GAP + '0');
            retString.push_back('\n');
            j++;
        }
    }
    return retString;
}

// used for debugging the matrix values
void EDistance::printMatrix() {
    for (unsigned i = 0; i < mtx.size(); i++) {
        for (unsigned j = 0; j < mtx[i].size(); j++) {
            std::cout << mtx[i][j] << std::setw(4);
        }
        std::cout << std::endl;
    }
}
