#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}


int32_t main(){
    fast_io();

    int32_t l, r;
    cin >> l >> r;
    int32_t max = INT32_MIN;
    for(int i=l; i<=r; i++){
        for(int j=i; j<=r; j++){
            if((i ^ j) > max) max = i ^ j;
        }
    }
    cout << max << endl;



    return 0;
}