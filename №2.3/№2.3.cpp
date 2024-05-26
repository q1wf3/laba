#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream inputFile("a.txt");
    if (!inputFile.is_open()) {
        cerr << "Err" << endl;
        return 1;
    }

    ofstream outputFile("a2.txt");
    if (!outputFile.is_open()) {
        cerr << "Err" << endl;
        inputFile.close();
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        string newLine;
        for (char c : line) {
            if (!isdigit(c)) {
                newLine += c;
            }
        }

        outputFile << newLine << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Файл успешно обработан и сохранен в a2.txt" << endl;
    return 0;
}
