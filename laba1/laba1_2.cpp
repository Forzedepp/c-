#include <stdio.h>
#define PR(x) printf("x=%p, *x=%d, &x=%p\n", (void*)x, *x, (void*)&x)

int main() {
    int mas[] = { 100, 200, 300 };
    int* ptr1 = mas;
    int* ptr2 = &mas[2];

    PR(ptr1); // Вывод: адрес ptr1, значение *ptr1, адрес &ptr1
    ptr1++;
    PR(ptr1); // Сдвиг указателя на следующий элемент
    PR(ptr2); // Адрес ptr2, значение *ptr2 (300)
    ++ptr2;
    printf("ptr2 - ptr1 = %td\n", ptr2 - ptr1); // Разница в элементах

    return 0;
}
