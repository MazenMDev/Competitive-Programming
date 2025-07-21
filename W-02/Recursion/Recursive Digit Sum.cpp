#include <iostream>
#include <string>
using namespace std;

void times(string number, int& i, long long& sum) {
    if (i == number.length()) return;
    sum += (number[i] - '0');
    i++;
    times(number, i, sum);
}

void super(string number, int& k, int i, long long& sum) {
    times(number, i, sum);
    sum *= k;
    while (sum >= 10) {
        i = 0;
        number = to_string(sum);
        sum = 0;
        times(number, i, sum);
    }
}

int main() {
    string number;
    cin >> number;
    int k;
    cin >> k;
    long long sum = 0;
    int i = 0;
    super(number, k, i, sum);
    cout << sum << endl;
}