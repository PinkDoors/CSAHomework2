//------------------------------------------------------------------------------
// NumbersEncryption.h - содержит описание строки, зашифрованной заменой символов на числа.
//------------------------------------------------------------------------------

#include "Encryption.h"

// Строка, зашифрованная заменой символов
struct NumbersEncryption : Encryption {
    int encryptedString[256]; // Зашифрованная строка
    struct PairOfCharInt {
        char first;
        int second;
    } *symbols;

    // Инициализация и шифрование случайными данными
    NumbersEncryption();

    // Инициализация и шифрование данными из файла
    NumbersEncryption(std::ifstream &ifst);

    // Шифрование случайными данными
    void RandomEncrypt();

    // Шифрование данными из файла
    void Encrypt(std::ifstream &ifst);

    // Инициализация массива пар [символ, число]
    void Init();

    // Вывод зашифрованной строки
    void Out(std::ofstream &ofst) override;
};
