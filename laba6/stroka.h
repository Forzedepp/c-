#ifndef STROKA_H
#define STROKA_H

#include "my_string_functions.h"

class Stroka {
private:
    char* str;
    int capacity;

public:
    // Конструкторы
    Stroka(); // По умолчанию (80 символов)
    Stroka(const char* s); // Инициализация строкой
    Stroka(int size); // Динамический размер
    Stroka(const Stroka& other); // Копирующий конструктор

    // Деструктор
    ~Stroka();

    // Операторы
    Stroka& operator=(const Stroka& other); // Присваивание
    Stroka operator+(const Stroka& other) const; // Конкатенация
    bool operator==(const Stroka& other) const; // Сравнение

    // Методы
    int dlina() const; // Длина строки
    void vvod(); // Ввод строки
    void vyvod() const; // Вывод строки
};

#endif 