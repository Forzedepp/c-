#include "stroka.h"
#include <iostream>

// Конструктор по умолчанию
Stroka::Stroka() {
    capacity = 80;
    str = new char[capacity];
    str[0] = '\0';
}

// Конструктор с инициализацией строкой
Stroka::Stroka(const char* s) {
    int len = myStrlen((char*)s) + 1;
    capacity = len;
    str = new char[capacity];
    myStrcpy(str, (char*)s);
}

// Конструктор с заданным размером
Stroka::Stroka(int size) {
    capacity = size;
    str = new char[capacity];
    str[0] = '\0';
}

// Копирующий конструктор
Stroka::Stroka(const Stroka& other) {
    capacity = other.capacity;
    str = new char[capacity];
    myStrcpy(str, other.str);
}

// Деструктор
Stroka::~Stroka() {
    delete[] str;
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& other) {
    if (this != &other) {
        if (capacity < other.dlina() + 1) {
            delete[] str;
            capacity = other.dlina() + 1;
            str = new char[capacity];
        }
        myStrcpy(str, other.str);
    }
    return *this;
}

// Оператор конкатенации (+)
Stroka Stroka::operator+(const Stroka& other) const {
    int newCapacity = dlina() + other.dlina() + 1;
    Stroka result(newCapacity);
    myStrcpy(result.str, str);
    myStrcat(result.str, other.str);
    return result;
}

// Оператор сравнения (==)
bool Stroka::operator==(const Stroka& other) const {
    return myStrcmp(str, other.str) == 0;
}

// Метод длины строки
int Stroka::dlina() const {
    return myStrlen(str);
}

// Метод ввода строки
void Stroka::vvod() {
    std::cin >> str; // Внимание: возможна утечка памяти при длинных строках
}

// Метод вывода строки
void Stroka::vyvod() const {
    std::cout << str;
}