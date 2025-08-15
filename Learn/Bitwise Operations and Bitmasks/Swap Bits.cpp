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

    int32_t number;
    cin >> number;
    uint32_t num;
    while(number--){
        cin >> num;
        uint32_t result = 0;
        for(int i=0; i<32; i++){
            uint32_t bit1 = (num >> i) & 1;
            uint32_t bit2 = (num >> (i+1)) & 1;

            result |= (bit1 << (i+1));
            result |= (bit2 << i);
        }
        cout << result << endl;
    }


    return 0;
}
