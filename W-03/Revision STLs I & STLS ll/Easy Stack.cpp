#include <iostream> 
#include <stack>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int number;
    cin >> number;
    cin.ignore();
    stack<int>st;
    int command, num;
    while (number--) {
        cin >> command;
        if (command == 1) {
            cin >> num;
            st.push(num);
        }
        else if (command == 2) {
            if (!st.empty()) st.pop();
        }
        else if (command == 3) {
            if (st.empty()) cout << "Empty!\n";
            else cout << st.top() << '\n';
        }
    }

}