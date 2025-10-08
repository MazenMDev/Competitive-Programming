#include <iostream>
using namespace std;

void solve(int number, int l, int& count) {
    if (number <= l) {
        count++;
        return;
    }
    solve(number / 2, l, count);
    solve(number - number / 2, l, count);
}

int main() {
    int number, l;
    while (cin >> number >> l) {
        int count = 0;
        solve(number, l, count);
        cout << count << endl;
    }
    return 0;
}