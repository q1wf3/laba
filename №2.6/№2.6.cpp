#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("f.txt");

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    int number;
    int count_even = 0;
    while (file >> number) {
        if (number % 2 == 0) {
            count_even++;
        }
    }

    file.close();

    ofstream result_file("result.txt");

    if (!result_file.is_open()) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    result_file << "Количество четных чисел: " << count_even << endl;

    result_file.close();

    return 0;
}
