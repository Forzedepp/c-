#include <iostream>
#include "stroka.h"

int main() {
    Stroka s1("qwert");
    Stroka s3;
    Stroka s4("5$1"); // Инициализация строки
    Stroka s5;

    // Ввод строки
    std::cout << "Введите строку для s3: ";
    s3.vvod();

    // Присваивание через operator=
    s3 = Stroka("asdfg"); // Используем конструктор и оператор присваивания
    std::cout << "s3 после присваивания: ";
    s3.vyvod();
    std::cout << std::endl;

    // Конкатенация
    s5 = s1 + s3 + s4;
    std::cout << "s5 = " << s5.dlina() << " символов: ";
    s5.vyvod();
    std::cout << std::endl;

    // Сравнение строк
    if (s1 == s5) {
        std::cout << "Строки s1 и s5 равны" << std::endl;
    }
    else if (s1 == s4) {
        std::cout << "Строки s1 и s4 равны" << std::endl;
    }
    else {
        std::cout << "Строки не равны" << std::endl;
    }

    return 0;
}