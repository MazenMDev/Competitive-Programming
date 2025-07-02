#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int table[10][10];
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number ; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 1;
            }
            else {
                table[i][j] = table[i][j - 1] + table[i - 1][j];
            }
        }
    }
    cout << table[number-1][number-1] << endl;
}