#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Сортировка выбором (мини-макс)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 2. Сортировка пузырьком
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 3. Быстрая сортировка (Quick Sort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 4. Сортировка четных по возрастанию, нечетных по убыванию
void sortEvenOdd(int arr[], int n) {
    vector<int> evens, odds;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evens.push_back(arr[i]);
        }
        else {
            odds.push_back(arr[i]);
        }
    }
    sort(evens.begin(), evens.end()); // Четные: по возрастанию
    sort(odds.begin(), odds.end(), greater<int>()); // Нечетные: по убыванию

    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = evens[e++];
        }
        else {
            arr[i] = odds[o++];
        }
    }
}

// 5. Сортировка интервала [m1, m2] по возрастанию
void sortRangeAsc(int arr[], int m1, int m2) {
    sort(arr + m1, arr + m2 + 1);
}

// 6. Сортировка интервала [m1, m2] по убыванию
void sortRangeDesc(int arr[], int m1, int m2) {
    sort(arr + m1, arr + m2 + 1, greater<int>());
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    // 1. Сортировка выбором
    selectionSort(arr, n);
    cout << "После сортировки выбором: ";
    printArray(arr, n);

    // 2. Сортировка пузырьком
    bubbleSort(arr, n);
    cout << "После сортировки пузырьком: ";
    printArray(arr, n);

    // 3. Быстрая сортировка
    quickSort(arr, 0, n - 1);
    cout << "После быстрой сортировки: ";
    printArray(arr, n);

    // 4. Сортировка четных/нечетных
    sortEvenOdd(arr, n);
    cout << "После сортировки четных ↑ / нечетных ↓: ";
    printArray(arr, n);

    // 5. Сортировка интервала [1, 4] по возрастанию
    sortRangeAsc(arr, 1, 4);
    cout << "После сортировки интервала [1,4] ↑: ";
    printArray(arr, n);

    // 6. Сортировка интервала [0, 3] по убыванию
    sortRangeDesc(arr, 0, 3);
    cout << "После сортировки интервала [0,3] ↓: ";
    printArray(arr, n);

    return 0;
}
