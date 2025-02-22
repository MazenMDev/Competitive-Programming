#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n >= -2147483648 && n <= 2147483647) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

}