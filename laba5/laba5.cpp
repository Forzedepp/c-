#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>   // для isspace
#include <cstring>  // для strcmp

using namespace std;

// 1. Вывод содержимого файла на экран (упрощенная версия)
void printFile(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    char ch;
    while (file.get(ch)) cout << ch;
    file.close();
}

// 2. Подсчет "пустых" и "непустых" символов
void countSymbols(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    int empty = 0, nonEmpty = 0;
    char ch;
    while (file.get(ch)) {
        // Пустые символы: пробелы, управляющие символы (коды < 32)
        if (isspace(ch) || ch < 32) empty++;
        else nonEmpty++;
    }
    cout << "Пустых символов: " << empty << endl;
    cout << "Непустых символов: " << nonEmpty << endl;
    file.close();
}

// 3. Поиск подстроки в файле и запись результатов в отдельный файл
void findSubstring(const char* filename, const string& substring) {
    ifstream file(filename);
    ofstream result("result.txt");
    if (!file || !result) {
        cerr << "Ошибка открытия файлов!" << endl;
        return;
    }
    string line;
    int lineNum = 0;
    while (getline(file, line)) {
        lineNum++;
        size_t pos = line.find(substring);
        if (pos != string::npos) {
            result << "Строка " << lineNum << ", позиция " << pos << ": " << line << endl;
        }
    }
    file.close();
    result.close();
}

// 4. Перенос номеров страниц из первой строки в последнюю
void processPages(const char* filename) {
    ifstream inFile(filename);
    ofstream outFile("processed_" + string(filename));
    if (!inFile || !outFile) {
        cerr << "Ошибка открытия файлов!" << endl;
        return;
    }
    string pageNumber;
    vector<string> pageLines;
    string line;
    while (getline(inFile, line)) {
        if (line.find("\\f") != string::npos) { // Найден символ перевода страницы
            if (!pageNumber.empty()) {
                pageLines.back() = pageNumber; // Замена последней строки
                pageNumber.clear();
            }
        }
        else if (pageLines.empty()) { // Первая строка страницы
            pageNumber = line;
        }
        else {
            pageLines.push_back(line);
        }
    }
    // Запись обработанных данных
    for (const auto& l : pageLines) outFile << l << endl;
    inFile.close();
    outFile.close();
}

// 5-6. Шифратор файлов с использованием ключа из командной строки
void encryptFile(const char* inputFile, const char* outputFile, const string& key) {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);
    if (!in || !out) {
        cerr << "Ошибка открытия файлов!" << endl;
        return;
    }
    size_t keyIndex = 0;
    char ch;
    while (in.get(ch)) {
        ch ^= key[keyIndex % key.size()]; // Циклическое применение ключа
        out.put(ch);
        keyIndex++;
    }
    in.close();
    out.close();
}

// Главная функция с обработкой аргументов командной строки
int main(int argc, char* argv[]) {
    // Режим шифрования (аргументы командной строки)
    if (argc == 4 && strcmp(argv[1], "-encrypt") == 0) {
        encryptFile(argv[2], argv[3], argv[1]);
        return 0;
    }

    // Интерактивное меню
    int choice;
    cout << "1. Вывести файл на экран\n2. Подсчет символов\n3. Поиск подстроки\n4. Обработка страниц\n5. Шифрование\nВыберите действие: ";
    cin >> choice;

    string filename, substring, key;
    switch (choice) {
    case 1:
        cout << "Введите имя файла: ";
        cin >> filename;
        printFile(filename.c_str());
        break;
    case 2:
        cout << "Введите имя файла: ";
        cin >> filename;
        countSymbols(filename.c_str());
        break;
    case 3:
        cout << "Введите имя файла и подстроку: ";
        cin >> filename >> substring;
        findSubstring(filename.c_str(), substring);
        break;
    case 4:
        cout << "Введите имя файла: ";
        cin >> filename;
        processPages(filename.c_str());
        break;
    case 5:
        cout << "Введите входной файл, выходной файл и ключ: ";
        cin >> filename >> substring >> key;
        encryptFile(filename.c_str(), substring.c_str(), key);
        break;
    default:
        cerr << "Неверный выбор!" << endl;
    }
    return 0;
}
