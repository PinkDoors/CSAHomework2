#include <iostream>

//------------------------------------------------------------------------------
// CyclicShiftEncryption.h - содержит реализацию строки, зашифрованной циклическим сдвигом кода каждого символа на n.
//------------------------------------------------------------------------------

#include "CyclicShiftEncryption.h"

CyclicShiftEncryption::CyclicShiftEncryption() {
    size = rand() % 255;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < size; ++i) {
        int symbol = rand() % 62;
        sourceString[i] = alphanum[symbol];
    }
    shift = rand() % 1000;
    for (int i = 0; i < size; ++i) {
        encryptedString[i] = sourceString[i] + shift;
    }
}

CyclicShiftEncryption::CyclicShiftEncryption(std::ifstream &ifst) {
    ifst >> size;
    if (size > 256 || size < 0) {
        std::cout << "Incorrect size of the input string, the size is set to 0" << "\n";
        size = 0;
    }
    if (size > 0) {
        ifst >> sourceString;
    }
    ifst >> shift;
    for (int i = 0; i < size; ++i) {
        encryptedString[i] = sourceString[i] + shift;
    }
}

// Вывод зашифрованной строки
void CyclicShiftEncryption::Out(std::ofstream &ofst) {
    ofst << "Input string = ";
    for (int i = 0; i < size; ++i) {
        ofst << sourceString[i];
    }
    ofst << ".\n" << "\n";
    ofst << "The quotient of dividing the sum of "
            "the codes of an unencrypted "
            "string by the number of characters in "
            "this string = " << QuotientOfDivision();
    ofst << ".\n" << "\n";
    ofst << "Result of the encryption: ";
    for (int i = 0; i < size; ++i) {
        ofst << encryptedString[i];
    }
    ofst << ".\n";
}