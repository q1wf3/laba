#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream file("a.txt");
    if (!file.is_open()) {
        cout << "Err" << endl;
        return 1;
    }

    int count = 0;
    int num;
    int pos = 1;

    while (file >> num) {
        if (num < 0 && pos % 2 == 0) {
            count++;
        }
        pos++;
    }

    file.close();

    cout << "Количество отрицательных компонентов на чётных позициях: " << count << endl;

    return 0;
}
