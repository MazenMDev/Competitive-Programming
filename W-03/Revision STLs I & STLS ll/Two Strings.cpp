#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int number;
    cin >> number;
    string one, two;
    bool check;
    while (number--)
    {
        cin >> one >> two;
        check = false;
        for (int i = 0; i < one.size(); i++) {
            if (two.find(one[i]) != string::npos) {
                cout << "YES\n";
                check = true;
                break;
            }
        }
        if (!check) cout << "NO\n";
    }
}