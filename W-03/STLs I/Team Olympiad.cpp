#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int number;
    cin >> number;
    vector<int>num(number);
    vector<int>one, two, three;
    for (int i = 0; i < number; i++) {
        cin >> num[i];
        if (num[i] == 1)one.push_back(i +1);
        if (num[i] == 2)two.push_back(i+1);
        if (num[i] == 3)three.push_back(i+1);
    }
    if (one.empty() or two.empty() or three.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int mi = min({ one.size(), two.size(), three.size() });
    cout << mi << endl;
    for (int i = 0; i < mi; i++) {
        cout << one[i] << " " << two[i] << " " << three[i] << endl;
    }
}