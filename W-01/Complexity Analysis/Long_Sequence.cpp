#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int* num = new int[number];
    long long save = 0;
    for (int i = 0; i < number; i++) {
        cin >> num[i];
        save += num[i];
    }
    long long x;
    cin >> x;
    long long count = 0;
    count = x / save;
    save *= count;
    count *= number;

    for (int i = 0; i < number; i++) {
        save += num[i];
        count++;
        if (save > x)
        {
            break;
        }
    }
    cout << count << endl;
}