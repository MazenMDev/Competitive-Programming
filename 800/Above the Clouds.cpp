#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int num;
    string st;
    int check = 0;
    int k = 1;
    while (number--) {
        cin >> num;
        cin >> st;
        check = 0;
        k = 1;
        while (k < (num - 1)) {
            char save = st[k];
            for (int i = 0; i < num; i++) {
                if (i != k)
                {
                    if (st[i] == save) {
                        check = 1;
                        break;
                    }
                }
            }
            k++;
            if (check == 1) break;
        }
        if (check == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}