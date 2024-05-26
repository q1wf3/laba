#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("a.txt");
    ofstream fout("a2.txt");

    double x;
    while (fin >> x) {
        if (x != 0) {
            fout << x << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
