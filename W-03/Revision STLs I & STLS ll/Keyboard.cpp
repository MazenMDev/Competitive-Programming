#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    char dir;
    cin >> dir;
    string mes;
    cin >> mes;
    string save = "qwertyuiopasdfghjkl;zxcvbnm,./";
    for (int i = 0; i < mes.size(); i++) {
        int pos = save.find(mes[i]);
        if (dir == 'R') {
            cout << save[pos - 1];
        }
        else cout << save[pos + 1];
    }
}