#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Реализация функций работы со строками
int myStrlen1(char* p) {
    int i = 0;
    while (*p++) i++;
    return i;
}

int myStrlen2(char* p) {
    char* q = p;
    while (*q++);
    return q - p - 1;
}

int myStrlen3(char p[]) {
    int count = 0;
    while (p[count] != '\0') count++;
    return count;
}

char* myStrcpy(char* a, char* b) {
    char* start = a;
    while ((*a++ = *b++));
    return start;
}

void myStrcat(char* a, char* b) {
    while (*a) a++;
    while ((*a++ = *b++));
}

const char* myStrcmp(char* a, char* b) {
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return (*a == *b) ? "[identical]" : "[not identical]";
}

int main() {
    // Статические строки
    char S[] = "Hello ";
    char T[] = "Friend!";
    char U[80] = {};
    char V[] = "Hello Friend!";

    // Тестирование функций длины
    cout << "*****String_Length*****\n";
    cout << "str1: " << myStrlen1(S)
        << " | str2: " << myStrlen2(T)
        << " | str3: " << myStrlen3(S) << "\n\n";

    // Тестирование копирования
    myStrcpy(U, S);
    cout << "*****String_Copy*****\n"
        << "Результат: " << U << "\n\n";

    // Тестирование конкатенации
    myStrcat(U, T);
    cout << "*****String_Concat*****\n"
        << "Результат: " << U << "\n\n";

    // Тестирование сравнения
    cout << "*****String_Compare*****\n"
        << "Сравнение 1: " << myStrcmp(S, T) << "\n"
        << "Сравнение 2: " << myStrcmp(U, V) << "\n\n";

    // Динамическая память (malloc)
    char* str1 = (char*)malloc(20);
    char* str2 = (char*)malloc(20);
    myStrcpy(str1, S);
    myStrcpy(str2, T);

    cout << "*****Malloc_Test*****\n";
    cout << "Копирование: " << str1 << " | " << str2 << "\n";
    myStrcat(str1, str2);
    cout << "Конкатенация: " << str1 << "\n";
    cout << "Сравнение: " << myStrcmp(str1, V) << "\n\n";
    free(str1);
    free(str2);

    // Динамическая память (calloc)
    char* strC1 = (char*)calloc(100, sizeof(char));
    char* strC2 = (char*)calloc(100, sizeof(char));
    myStrcpy(strC1, S);
    myStrcpy(strC2, T);

    cout << "*****Calloc_Test*****\n";
    cout << "Копирование: " << strC1 << " | " << strC2 << "\n";
    myStrcat(strC1, strC2);
    cout << "Конкатенация: " << strC1 << "\n";
    cout << "Сравнение: " << myStrcmp(strC1, V) << "\n";
    free(strC1);
    free(strC2);

    return 0;
}
