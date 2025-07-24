#include <iostream>
#include <stack>
using namespace std;

int main() {
    int number;
    cin >> number;
    int num, del, t;
    string save, st;
    stack<string>store;
    while (number--)
    {
        cin >> num;
        if (num == 1) {
            cin >> st;
            store.push(save);
            save += st;
        }
        else if (num == 2) {
            cin >> del;
            store.push(save);
            while (del--) {
                if(!save.empty()) save.pop_back();
            }
        }
        else if (num == 3) {
            cin >> t;
            cout << save[t-1] << endl;
        }
        else if (num == 4) {
            if (!store.empty()) {
                save = store.top();
                store.pop();
            }
        }
    }
}