#include "stroka.h"
#include <iostream>

// ����������� �� ���������
Stroka::Stroka() {
    capacity = 80;
    str = new char[capacity];
    str[0] = '\0';
}

// ����������� � �������������� �������
Stroka::Stroka(const char* s) {
    int len = myStrlen((char*)s) + 1;
    capacity = len;
    str = new char[capacity];
    myStrcpy(str, (char*)s);
}

// ����������� � �������� ��������
Stroka::Stroka(int size) {
    capacity = size;
    str = new char[capacity];
    str[0] = '\0';
}

// ���������� �����������
Stroka::Stroka(const Stroka& other) {
    capacity = other.capacity;
    str = new char[capacity];
    myStrcpy(str, other.str);
}

// ����������
Stroka::~Stroka() {
    delete[] str;
}

// �������� ������������
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

// �������� ������������ (+)
Stroka Stroka::operator+(const Stroka& other) const {
    int newCapacity = dlina() + other.dlina() + 1;
    Stroka result(newCapacity);
    myStrcpy(result.str, str);
    myStrcat(result.str, other.str);
    return result;
}

// �������� ��������� (==)
bool Stroka::operator==(const Stroka& other) const {
    return myStrcmp(str, other.str) == 0;
}

// ����� ����� ������
int Stroka::dlina() const {
    return myStrlen(str);
}

// ����� ����� ������
void Stroka::vvod() {
    std::cin >> str; // ��������: �������� ������ ������ ��� ������� �������
}

// ����� ������ ������
void Stroka::vyvod() const {
    std::cout << str;
}