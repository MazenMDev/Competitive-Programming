#include <iostream> 
#include <deque>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int number;
    cin >> number;
    cin.ignore();
    deque<int>stack;
    int command, num;
    while (number--) {
        cin >> command;
        if (command == 1) {
            cin >> num;
            stack.push_back(num);
        }
        else if (command == 2) {
            if (!stack.empty()) stack.pop_back();
        }
        else if (command == 3) {
            if (stack.empty()) cout << "Empty!\n";
            else cout << stack.back() << '\n';
        }
    }

}