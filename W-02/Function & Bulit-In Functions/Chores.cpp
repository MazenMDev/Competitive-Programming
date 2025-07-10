#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int number;
    cin >> number;
    int k, x;
    cin >> k >> x;
    int* num = new int[number];

    int sum = 0;
    for (int i = 0; i < number; i++) {
        cin >> num[i];
    }
    sort(num, num + number);
    reverse(num, num + number);
    for (int i = 0; i < k; i++) {
        num[i] = x;
    }
    for (int i = 0; i < number; i++) {
        sum += num[i];
    }
    cout << sum << endl;
}