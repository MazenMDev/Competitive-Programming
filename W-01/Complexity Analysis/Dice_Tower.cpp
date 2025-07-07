#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int top;
    cin >> top;
    int check = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int bottom = 7 - top;
        if (top == a || top == b || bottom == a || bottom == b) {
            check = 0; 
        }
        top = bottom;
    }
    if (check == 0)
    {
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}
