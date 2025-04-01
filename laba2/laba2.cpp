#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#define N 5

using namespace std;

// Прототипы функций
void printMatrix(float m[N][N]);
void maximum(float m[N][N]);
void minimum(float m[N][N]);
void upperTriangleMax(float m[N][N]);
void upperTriangleMin(float m[N][N]);
void lowerTriangleMax(float m[N][N]);
void lowerTriangleMin(float m[N][N]);
void mainDiagMax(float m[N][N]);
void mainDiagMin(float m[N][N]);
void secondDiagMax(float m[N][N]);
void secondDiagMin(float m[N][N]);
void matrixAverage(float m[N][N]);
void lowerTriangleAverage(float m[N][N]);
void upperTriangleAverage(float m[N][N]);
void rowSums(float m[N][N]);
void columnSums(float m[N][N]);
void rowMins(float m[N][N]);
void rowMaxs(float m[N][N]);
void columnMins(float m[N][N]);
void columnMaxs(float m[N][N]);
void rowAverages(float m[N][N]);
void columnAverages(float m[N][N]);
void upperTriangleSum(float m[N][N]);
void lowerTriangleSum(float m[N][N]);
void closestToAverage(float m[N][N]);

int main() {
    float m[N][N];

    // Инициализация матрицы случайными значениями
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = rand() / 100.0f;
        }
    }

    printMatrix(m);

    // Вызов всех функций обработки
    maximum(m);
    minimum(m);
    upperTriangleMax(m);
    upperTriangleMin(m);
    lowerTriangleMax(m);
    lowerTriangleMin(m);
    mainDiagMax(m);
    mainDiagMin(m);
    secondDiagMax(m);
    secondDiagMin(m);
    matrixAverage(m);
    lowerTriangleAverage(m);
    upperTriangleAverage(m);
    rowSums(m);
    columnSums(m);
    rowMins(m);
    rowMaxs(m);
    columnMins(m);
    columnMaxs(m);
    rowAverages(m);
    columnAverages(m);
    upperTriangleSum(m);
    lowerTriangleSum(m);
    closestToAverage(m);

    return 0;
}

void printMatrix(float m[N][N]) {
    cout << "Матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << fixed << setprecision(2) << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void maximum(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > maxVal) maxVal = m[i][j];
        }
    }
    cout << "Максимум матрицы: " << maxVal << endl;
}

void minimum(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < minVal) minVal = m[i][j];
        }
    }
    cout << "Минимум матрицы: " << minVal << endl;
}

void upperTriangleMax(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > maxVal) maxVal = m[i][j];
        }
    }
    cout << "Максимум верхнетреугольной части: " << maxVal << endl;
}

void upperTriangleMin(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < minVal) minVal = m[i][j];
        }
    }
    cout << "Минимум верхнетреугольной части: " << minVal << endl;
}

void lowerTriangleMax(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] > maxVal) maxVal = m[i][j];
        }
    }
    cout << "Максимум нижнетреугольной части: " << maxVal << endl;
}

void lowerTriangleMin(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] < minVal) minVal = m[i][j];
        }
    }
    cout << "Минимум нижнетреугольной части: " << minVal << endl;
}

void mainDiagMax(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 1; i < N; i++) {
        if (m[i][i] > maxVal) maxVal = m[i][i];
    }
    cout << "Максимум главной диагонали: " << maxVal << endl;
}

void mainDiagMin(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 1; i < N; i++) {
        if (m[i][i] < minVal) minVal = m[i][i];
    }
    cout << "Минимум главной диагонали: " << minVal << endl;
}

void secondDiagMax(float m[N][N]) {
    float maxVal = m[0][N - 1];
    for (int i = 1; i < N; i++) {
        if (m[i][N - 1 - i] > maxVal) maxVal = m[i][N - 1 - i];
    }
    cout << "Максимум побочной диагонали: " << maxVal << endl;
}

void secondDiagMin(float m[N][N]) {
    float minVal = m[0][N - 1];
    for (int i = 1; i < N; i++) {
        if (m[i][N - 1 - i] < minVal) minVal = m[i][N - 1 - i];
    }
    cout << "Минимум побочной диагонали: " << minVal << endl;
}

void matrixAverage(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    cout << "Среднее арифметическое матрицы: " << sum / (N * N) << endl;
}

void lowerTriangleAverage(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    cout << "Среднее нижнетреугольной части: " << sum / count << endl;
}

void upperTriangleAverage(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    cout << "Среднее верхнетреугольной части: " << sum / count << endl;
}

void rowSums(float m[N][N]) {
    cout << "Суммы строк:" << endl;
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        cout << "Строка " << i + 1 << ": " << sum << endl;
    }
}

void columnSums(float m[N][N]) {
    cout << "Суммы столбцов:" << endl;
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        cout << "Столбец " << j + 1 << ": " << sum << endl;
    }
}

void rowMins(float m[N][N]) {
    cout << "Минимумы строк:" << endl;
    for (int i = 0; i < N; i++) {
        float minVal = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] < minVal) minVal = m[i][j];
        }
        cout << "Строка " << i + 1 << ": " << minVal << endl;
    }
}

void rowMaxs(float m[N][N]) {
    cout << "Максимумы строк:" << endl;
    for (int i = 0; i < N; i++) {
        float maxVal = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] > maxVal) maxVal = m[i][j];
        }
        cout << "Строка " << i + 1 << ": " << maxVal << endl;
    }
}

void columnMins(float m[N][N]) {
    cout << "Минимумы столбцов:" << endl;
    for (int j = 0; j < N; j++) {
        float minVal = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] < minVal) minVal = m[i][j];
        }
        cout << "Столбец " << j + 1 << ": " << minVal << endl;
    }
}

void columnMaxs(float m[N][N]) {
    cout << "Максимумы столбцов:" << endl;
    for (int j = 0; j < N; j++) {
        float maxVal = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] > maxVal) maxVal = m[i][j];
        }
        cout << "Столбец " << j + 1 << ": " << maxVal << endl;
    }
}

void rowAverages(float m[N][N]) {
    cout << "Средние строк:" << endl;
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        cout << "Строка " << i + 1 << ": " << sum / N << endl;
    }
}

void columnAverages(float m[N][N]) {
    cout << "Средние столбцов:" << endl;
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        cout << "Столбец " << j + 1 << ": " << sum / N << endl;
    }
}

void upperTriangleSum(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
        }
    }
    cout << "Сумма верхнетреугольной части: " << sum << endl;
}

void lowerTriangleSum(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
        }
    }
    cout << "Сумма нижнетреугольной части: " << sum << endl;
}

void closestToAverage(float m[N][N]) {
    float avg = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            avg += m[i][j];
        }
    }
    avg /= (N * N);

    float closest = m[0][0];
    float minDiff = fabs(m[0][0] - avg);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = fabs(m[i][j] - avg);
            if (diff < minDiff) {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }

    cout << "Элемент, ближайший к среднему (" << avg << "): " << closest << endl;
}
