#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int main() {
    fast_io();

    int64_t number;
    cin >> number;
    while (number--) {
        int64_t n;
        cin >> n;
        vector<int64_t> num(n);
        int64_t count = 0;
        int64_t tot = 0;
        int64_t c = 0;
        
        for (int i=0; i<n; i++ ) {
            cin >> num[i];
            if (num[i] % 2 == 0) {
                count++;
            }
            else {
                tot += num[i];
                c++;
                if (c == 3) {
                    if (tot % 2 != 0) {
                        cout << "YES\n";
                        break;
                    }
                }
            }
        }
        cout << "count: " << count << endl;
        if (count == n) {
            cout << "NO\n";
            continue;
        }
    }

    return 0;
}