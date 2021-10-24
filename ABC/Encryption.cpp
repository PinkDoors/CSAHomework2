#include <iostream>
#include <ctime>

//------------------------------------------------------------------------------
// Encryption.cpp - содержит процедуры связанные с шифрованием поступившей строки
//------------------------------------------------------------------------------

#include "Encryption.h"
#include "CyclicShiftEncryption.h"
#include "NumbersEncryption.h"
#include "SymbolsEncryption.h"

Encryption *Encryption::In(std::ifstream &ifst) {
    Encryption *sp;
    int key;
    ifst >> key;
    switch (key) {
        case 1:
            sp = new CyclicShiftEncryption(ifst);
            sp->PrintSourceString();
            return sp;
        case 2:
            sp = new NumbersEncryption(ifst);
            sp->PrintSourceString();
            return sp;
        case 3:
            sp = new SymbolsEncryption(ifst);
            sp->PrintSourceString();
            return sp;
        default:
            std::cout << "Invalid input encryption type." << "\n";
            exit(-1);
    }
}

void Encryption::PrintSourceString() {
    std::cout << "String " << "\"";
    for (int i = 0; i < size; ++i) {
        std::cout << sourceString[i];
    }
    std::cout << "\" was encrypted." << "\n";
}

Encryption *Encryption::InRnd() {
    Encryption *sp;
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            sp = new CyclicShiftEncryption();
            return sp;
        case 2:
            sp = new NumbersEncryption();
            return sp;
        case 3:
            sp = new SymbolsEncryption();
            return sp;
        default:
            return 0;
    }
}
