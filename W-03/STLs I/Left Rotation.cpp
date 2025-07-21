#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    cin >> number;
    int d;
    cin >> d;
    vector<int>arr(number);
    for (int i = 0; i < number; i++) {
        cin >> arr[i];
    }
    while (d--) {
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
    }
    for (int i = 0; i < number; i++) {
        cout << arr[i] << " ";
    }
}