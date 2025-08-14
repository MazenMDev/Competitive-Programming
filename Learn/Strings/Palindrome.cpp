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

    string word;
    cin >> word;
    string save = word;
    reverse(word.begin(), word.end());
    cout << ((save == word) ? "YES" : "NO") << endl;


    return 0;
}