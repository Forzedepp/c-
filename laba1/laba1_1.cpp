#include <iostream>
using namespace std;

int power(int x, int n) {
    int p = 1;
    for (int i = 0; i < n; i++) {
        p *= x;
    }
    return p;
}

int main() {
    int base = 3; // Основание
    for (int i = 0; i < 10; i++) {
        int result = power(base, i);
        cout << base << "^" << i << " = " << result << endl;
    }
    return 0;
}
