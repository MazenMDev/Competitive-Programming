#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    set<int>bulbs;
    int number, bulb;
    cin >> number >> bulb;
    int row;
    while (number--)
    {
        cin >> row;
        int *bu = new int[row];
        for (int i = 0; i < row; i++) {
            cin >> bu[i];
            bulbs.insert(bu[i]);
        }
    }
    if (bulbs.size() == bulb) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
