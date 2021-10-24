#include <iostream>

//------------------------------------------------------------------------------
// NumbersEncryption.cpp - содержит реализацию строки, зашифрованной заменой символов на числа.
//------------------------------------------------------------------------------

#include "NumbersEncryption.h"

NumbersEncryption::NumbersEncryption() {
    Init();
    RandomEncrypt();
}

NumbersEncryption::NumbersEncryption(std::ifstream &ifst) {
    ifst >> size;
    if (size > 256 || size < 0) {
        std::cout << "Incorrect size of the input string, the size is set to 0" << "\n";
        size = 0;
    }
    if (size > 0) {
        ifst >> sourceString;
    }
    Init();
    Encrypt(ifst);
}

void NumbersEncryption::RandomEncrypt() {
    size = rand() % 255;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < size; ++i) {
        int symbol = rand() % 62;
        sourceString[i] = alphanum[symbol];
    }
    for (int j = 0; j < 62; ++j) {
        int newInteger = rand() % 1000;
        symbols[j].second = newInteger;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 62; ++j) {
            if (sourceString[i] == symbols[j].first) {
                encryptedString[i] = symbols[j].second;
            }
        }
    }
}

void NumbersEncryption::Init() {
    symbols = new NumbersEncryption::PairOfCharInt[62];
    int numberOfSymbol = 0;
    for (int i = 0; i < 10; ++i) {
        symbols[numberOfSymbol].first = i + 48;
        symbols[numberOfSymbol].second = 0;
        ++numberOfSymbol;
    }
    for (int i = 17; i < 43; ++i) {
        symbols[numberOfSymbol].first = i + 48;
        symbols[numberOfSymbol].second = 0;
        ++numberOfSymbol;
    }
    for (int i = 49; i < 75; ++i) {
        symbols[numberOfSymbol].first = i + 48;
        symbols[numberOfSymbol].second = 0;
        ++numberOfSymbol;
    }
}

void NumbersEncryption::Encrypt(std::ifstream &ifst) {
    int numberOfSymbols;
    ifst >> numberOfSymbols;
    for (int i = 0; i < numberOfSymbols; ++i) {
        char oldSymbol;
        int newInteger;
        ifst >> oldSymbol >> newInteger;
        for (int j = 0; j < 62; ++j) {
            if (symbols[j].first == oldSymbol) {
                symbols[j].second = newInteger;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 62; ++j) {
            if (sourceString[i] == symbols[j].first) {
                encryptedString[i] = symbols[j].second;
            }
        }
    }
}

void NumbersEncryption::Out(std::ofstream &ofst) {
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