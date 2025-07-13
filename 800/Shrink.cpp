#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int number;
    cin >> number;
    int n;

    for (int i = 0; i < number; i++) {
        cin >> n;
        int save = n;
        int* num = new int[n];
        num[0] = 1;
        for (int j = 1; j < n; j++) {
            num[j] = save;
            save--;
        }
        for (int j = 0; j < n; j++) {
            cout << num[j] << " ";
        }
        cout << endl;
    }
}