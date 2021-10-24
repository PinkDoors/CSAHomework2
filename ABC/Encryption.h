#ifndef __shape__
#define __shape__

#include <fstream>

//------------------------------------------------------------------------------
// Encryption.h - содержит описание обобщающей зашифрованной строки,
//------------------------------------------------------------------------------

// структура, обобщающая все имеющиеся фигуры
struct Encryption {
    char sourceString[256]; // Исходная строка
    int size = 0;

    // Частное от деления суммы кодов незашифрованной строки на число символов в этой строке
    double QuotientOfDivision() {
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += sourceString[i];
        }
        if (size == 0) {
            return 0;
        }
        return sum / size;
    }

    // Вывод исходной строки, результата общей функции и зашифрованной строки в поток
    virtual void Out(std::ofstream &ofst) = 0;

    // Ввод обобщенной фигуры
    static Encryption *In(std::ifstream &ifst);

    // Случайный ввод обобщенной фигуры
    static Encryption *InRnd();

    // Выводи исходной строки в консоль
    void PrintSourceString();
};

#endif
