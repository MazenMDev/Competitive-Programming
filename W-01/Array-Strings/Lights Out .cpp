#include <iostream>
using namespace std;

int main() {
    int mat[3][3];
    int ans[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int tot = mat[i][j];

            if (i > 0) tot += mat[i - 1][j];
            if (i < 2) tot += mat[i + 1][j];
            if (j > 0) tot += mat[i][j - 1];
            if (j < 2) tot += mat[i][j + 1];

            if (tot % 2 == 0)
                ans[i][j] = 1;
            else
                ans[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}
