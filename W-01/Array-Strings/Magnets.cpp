#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    cin >> number;
    string num, prev;
    int count = 0;
    for (int i = 0; i < number; i++) {
        cin >> num;
        if (num != prev)
        {
            count++;
        }
        prev = num;
    }
    cout << count << endl;
}