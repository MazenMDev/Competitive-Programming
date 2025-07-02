#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int wires[105]; 
    for (int i = 0; i < n; i++) {
        cin >> wires[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; 
        if (x - 1 >= 0) {
            wires[x - 1] += y - 1;
        }
        if (x + 1 < n) {
            wires[x + 1] += wires[x] - y;
        }
        wires[x] = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << wires[i] << endl;
    }
}
