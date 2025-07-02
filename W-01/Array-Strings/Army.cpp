#include <iostream>
using namespace std;

int main() {
    int nR;
    int y[100];
    int from, to;
    cin >> nR;
    for (int i = 0; i < nR - 1; i++) {
        cin >> y[i];
    }
    cin >> from >> to;
    int count = 0;
    for (int i = from - 1; i < to - 1; i++) {
        count += y[i];
    }
    cout << count << endl;
}