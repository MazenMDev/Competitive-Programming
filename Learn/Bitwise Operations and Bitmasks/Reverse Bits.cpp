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

    int32_t number;
    cin >> number;
    uint32_t num;
    while(number--){
        cin >> num;
        uint32_t result = 0;
        for(int i=0; i<32; i++){
            uint32_t bit = num & 1;
            result = (result << 1) | bit;
            num >>= 1;
        }
        cout << result << endl;
    }


    return 0;
}