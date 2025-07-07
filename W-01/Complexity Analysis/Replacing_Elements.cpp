#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int number;
    cin >> number;
    int n, m;
    int check1, check2;
    int sum;
    for (int i = 0; i < number; i++) {
        cin >> n >> m;
        check1 = -1; check2 = -1;
        sum = 0;
        int* num = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> num[j];
            if (num[j] > m)
            {
                check1 = 0;
            }
        }
        if (check1 == 0)
        {
            sort(num, num + n);
            sum = num[0] + num[1];
            if (sum > m)
            {
                check2 = 0;
            }
        }
        if (check1 == 0 and check2 == 0)
        {
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
}