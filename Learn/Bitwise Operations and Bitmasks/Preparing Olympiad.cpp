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

    int32_t n;
    cin >> n;
    int32_t l, r, x;
    cin >> l >> r >> x;
    vector<int32_t> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int32_t count = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int bits = __builtin_popcount(mask);
        if (bits < 2) continue;  
        
        int sum = 0;
        int mx = INT_MIN, mn = INT_MAX;
        for (int j = 0; j < n; j++) {
            if ((mask >> j) & 1) {
                sum += num[j];
                mx = max(mx, num[j]);
                mn = min(mn, num[j]);
            }
        }

        if (sum >= l && sum <= r && (mx - mn) >= x) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
