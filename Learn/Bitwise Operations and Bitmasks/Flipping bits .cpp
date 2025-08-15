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

    int64_t number;
    cin >> number;
    while (number--) {
        int64_t n;
        cin >> n;

        for(int i=0; i < 32;i++){
            n ^= (1ll<<i);
        }

        cout << n << endl;
    }

    return 0;
}
