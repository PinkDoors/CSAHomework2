//------------------------------------------------------------------------------
// SymbolsEncryption.h - содержит описание строки, зашифрованной заменой символов на другие символы.
//------------------------------------------------------------------------------

#include "Encryption.h"

// Строка, зашифрованная заменой символов
struct SymbolsEncryption : Encryption {
    // Зашифрованная строка.
    char encryptedString[256];
    // Указатель на массив пар [символ, символ]
    struct PairOfCharChar {
        char first;
        char second;
    } *symbols;

    // Инициализация и шифрование случайными данными
    SymbolsEncryption();

    // Инициализация и шифрование данными из файла
    SymbolsEncryption(std::ifstream &ifst);

    // Шифрование случайными данными
    void RandomEncrypt();

    // Шифрование данными из файла
    void Encrypt(std::ifstream &ifst);

    // Инициализация массива пар [символ, символ]
    void Init();

    // Вывод зашифрованной строки.
    void Out(std::ofstream &ofst) override;
};
