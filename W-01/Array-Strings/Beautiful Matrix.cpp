#include <iostream>
using namespace std;

int main() {
    int mat[5][5];
    int posi, posj;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                posi = i;
                posj = j;
            }

        }
    }
    int count = 0;
    while (posi < 2) {
        posi += 1;
        count++;
    }
    while (posi > 2) {
        posi -= 1;
        count++;
    }
    while (posj < 2) {
        posj += 1;
        count++;
    }
    while (posj > 2) {
        posj -= 1;
        count++;
    }
    cout << count << endl;
}