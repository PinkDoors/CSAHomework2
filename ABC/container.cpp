#include <iostream>

//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

void container::Init() {
    len = 0;
}

void container::Clear() {
    for (int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

void container::In(std::ifstream &ifst) {
    int numberOfElements;
    ifst >> numberOfElements;
    if (numberOfElements > 10000 || numberOfElements < 0) {
        std::cout << "Incorrect number of strings" << "\n";
        return;
    }
    for (int i = 0; i < numberOfElements; ++i) {
        if ((cont[len] = Encryption::In(ifst)) != 0) {
            len++;
        }
    }
}

void container::InRnd(int size) {
    for (int i = 0; i < size; ++i) {
        if ((cont[len] = Encryption::InRnd()) != 0) {
            len++;
        }
    }
}

void container::Out(std::ofstream &ofst) {
    ofst << "Container contains " << len << " elements." << "\n";
    for (int i = 0; i < len; i++) {
        ofst << "----------------------------------------------------" << "\n";
        ofst << i << ": ";
        cont[i]->Out(ofst);
    }
}

void Heapify(Encryption *arr[10000], int n, int i) {
    // Инициализируем наименьший элемент как корень.
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->QuotientOfDivision() < arr[smallest]->QuotientOfDivision())
        smallest = left;
    if (right < n && arr[right]->QuotientOfDivision() < arr[smallest]->QuotientOfDivision())
        smallest = right;

    // Если самый маленький элемент не является корнем, то меняем местами.
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        Heapify(arr, n, smallest);
    }
}

void container::HeapSort() {
    // Построение кучи (перегруппируем массив)
    for (int i = len / 2 - 1; i >= 0; i--)
        Heapify(cont, len, i);
    // Один за другим извлекаем элементы из кучи.
    for (int j = len - 1; j >= 0; j--) {
        // Перемещаем текущий корень в конец.
        std::swap(cont[0], cont[j]);
        // вызываем процедуру Heapify на уменьшенной куче.
        Heapify(cont, j, 0);
    }
}


