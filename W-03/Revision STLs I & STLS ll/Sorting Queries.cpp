#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int number;
    cin >> number;
    queue<int>store;
    queue<int>store_new;
    priority_queue<int, vector<int>, greater<int> >big;
    int num;
    bool check = true;
    while (number--)
    {
        cin >> num;
        if (num == 1) {
            int save;
            cin >> save;
            if (check)store.push(save);
            else store_new.push(save);
        }
        else if (num == 2) {
            if (!store.empty() and check) {
                cout << store.front() << "\n";
                store.pop();
            }
            else if (!big.empty() and !check) {
                cout << big.top() << "\n";
                big.pop();
            }
            else if (!store_new.empty() and !check) {
                cout << store_new.front() << "\n";
                store_new.pop();
            }
        }
        else if (num == 3) {
            if (check) {
                while (!store.empty())
                {
                    big.push(store.front());
                    store.pop();
                }
            }
            else {
                while (!store_new.empty())
                {
                    big.push(store_new.front());
                    store_new.pop();
                }
            }
            check = false;
        }
    }
}