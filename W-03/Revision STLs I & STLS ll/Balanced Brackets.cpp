#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int number;
    cin >> number;
    string st;
    stack<char>save;
    bool check;
    while (number--)
    {
        while (!save.empty()) save.pop();
        check = true;
        cin >> st;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] == '(') save.push('(');
            else if (st[i] == '[') save.push('[');
            else if (st[i] == '{') save.push('{');
            else if (st[i] == ')') {
                if (i == 0) {
                    check = false;
                    cout << "NO\n";
                    break;
                }
                if (!save.empty() and save.top() == '(') save.pop();
                else {
                    check = false;
                    cout << "NO\n";
                    break;
                }
            }
            else if (st[i] == ']') {
                if (i == 0) {
                    check = false;
                    cout << "NO\n";
                    break;
                }
                if (!save.empty() and save.top() == '[') save.pop();
                else {
                    check = false;
                    cout << "NO\n";
                    break;
                }
            }
            else if (st[i] == '}') {
                if (i == 0) {
                    check = false;
                    cout << "NO\n";
                    break;
                }
                if (!save.empty() and save.top() == '{') save.pop();
                else {
                    check = false;
                    cout << "NO\n";
                    break;
                }
            }
        }
        if (save.empty() and check) cout << "YES\n";
        else if (check) cout << "NO\n";
    }
}