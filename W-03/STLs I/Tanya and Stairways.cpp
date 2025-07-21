#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    cin >> number;
    vector<int>num(number);
    int climb = 0;
    int count = 0;
    for (int i = 0; i < number; i++) {
        cin >> num[i];
        if (num[i] == 1) climb++;
    }
    cout << climb << endl;
    for (int i = 0; i < number; i++) {
        if (num[i] == 1 and i > 0) {
            cout << count << " ";
            count = 0;
        }
        count++;
    }
    cout << count << endl;
}