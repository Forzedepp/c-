#include "my_string_functions.h"

int myStrlen(char* str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

char* myStrcpy(char* dest, char* src) {
    char* start = dest;
    while ((*dest = *src) != '\0') {
        dest++;
        src++;
    }
    return start;
}

void myStrcat(char* dest, char* src) {
    while (*dest != '\0') {
        dest++;
    }
    while ((*dest = *src) != '\0') {
        dest++;
        src++;
    }
    *dest = '\0';
}

int myStrcmp(char* a, char* b) {
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return *a - *b;
}