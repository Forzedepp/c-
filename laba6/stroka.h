#ifndef STROKA_H
#define STROKA_H

#include "my_string_functions.h"

class Stroka {
private:
    char* str;
    int capacity;

public:
    // ������������
    Stroka(); // �� ��������� (80 ��������)
    Stroka(const char* s); // ������������� �������
    Stroka(int size); // ������������ ������
    Stroka(const Stroka& other); // ���������� �����������

    // ����������
    ~Stroka();

    // ���������
    Stroka& operator=(const Stroka& other); // ������������
    Stroka operator+(const Stroka& other) const; // ������������
    bool operator==(const Stroka& other) const; // ���������

    // ������
    int dlina() const; // ����� ������
    void vvod(); // ���� ������
    void vyvod() const; // ����� ������
};

#endif 