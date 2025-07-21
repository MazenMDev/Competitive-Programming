#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int number;
    cin >> number;
    int countrow, countcol;
    while (number--) {
        int r, c;
        cin >> r >> c;

        vector<string> matrix(r);
        int count = 0;
        countrow = 0; countcol = 0;
        for (int i = 0; i < r; i++) {
            cin >> matrix[i];
            int count1 = 0;
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '1') count1++;
            }
            if (count1 % 2 != 0) countrow++;
        }

        for (int j = 0; j < c; j++) {
            int count1 = 0;
            for (int i = 0; i < r; i++) {
                if (matrix[i][j] == '1') count1++;
            }
            if (count1 % 2 != 0) countcol++;
        }
        cout << max(countrow,countcol) << endl;
    }
}
