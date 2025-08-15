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
    int32_t count = 0;
    for(int i=0; i<32; i++){
        if(number & (1 << i)){
            count++;
        }
    }
    cout << count << endl;


    return 0;
}