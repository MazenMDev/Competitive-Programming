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

    int32_t num, number;
    cin >> num >> number;
    int64_t tot = 0;
    int32_t k = 2;
    while(k <= number){
        tot += pow(num, k);
        k+=2;
    }
    cout << tot << "\n";

    return 0;

}