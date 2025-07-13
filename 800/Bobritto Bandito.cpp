#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int n, m, l, r;
    while (number--) {
        cin >> n >> m >> l >> r;
        while ((r - l) != m)
        {
            if (r > 0) r--;
            else l++;
        }
        cout << l << " " << r << endl;
    }
}