#include <iostream>
using namespace std;

void check(int save, int& count) {
    if (save == 1) return;
    if (save % 2 == 0) {
        save /= 2;
    }
    else if (save % 3 == 0) {
        save /= 3;
    }
    else {
        count = -1;
        return;
    }
    check(save, ++count);
}

int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    if (b % a != 0) {
            cout << -1 << endl;
            return 0;
    }
    else if (b / a == 1) {
        cout << 0 << endl;
        return 0;
    }

    int save = b / a;
    check(save, count);
    cout << count << endl;
}