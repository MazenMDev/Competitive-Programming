#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    int sum = 1;
    for (int i = 0; i < number; i++) {
        sum *= 5;
    }
    cout << sum << endl;
}