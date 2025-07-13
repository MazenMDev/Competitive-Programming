#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int n, k;
    while (number--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            if (i < k) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}