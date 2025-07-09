#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int* num = new int[number * 2];
    int sum = 0;
    int max = -999999;
    for (int i = 0; i < number*2; i++) {
        cin >> num[i];
        if (i % 2 == 0) {
            sum -= num[i];
        }
        else {
            sum += num[i];
            if (max < sum)
            {
                max = sum;
            }
        }
    }
    cout << max << endl;
}