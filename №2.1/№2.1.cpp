#include <fstream>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream fin("a.txt");
    if (!fin.is_open()) {
        cout << "err" << endl;
        return 1;
    }

    int num_zeros = 0;
    double product = 1;
    double num;

    while (fin >> num) {
        if (num == 0) {
            num_zeros++;
        }
        else if (num < 1 && num > 0) {
            product *= num;
        }
    }

    fin.close();

    cout << "Количество нулевых элементов: " << num_zeros << endl;
    cout << "Произведение элементов меньших 1 и больших 0: " << product << endl;

    return 0;
}
