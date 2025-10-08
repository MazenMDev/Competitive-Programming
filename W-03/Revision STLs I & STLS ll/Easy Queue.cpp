#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int number;
    cin >> number;
    int command, num;
    queue<int>qu;
    while (number--)
    {
        cin >> command;
        if (command == 1) {
            cin >> num;
            qu.push(num);
        }
        else if (command == 2) {
            if (!qu.empty()) qu.pop();
        }
        else if (command == 3) {
            if (!qu.empty()) cout << qu.front() << '\n';
            else cout << "Empty!\n";
        }
    }
}