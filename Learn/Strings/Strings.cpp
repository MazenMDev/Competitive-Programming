#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
    fast_io();

    string w1, w2;
    cin >> w1 >> w2;
    cout << w1.size() << " " << w2.size() << endl;
    cout << w1 + w2 << endl;
    char save = w1[0];
    w1[0] = w2[0];
    w2[0] = save;
    cout << w1 << " " << w2 << endl;


    return 0;
}