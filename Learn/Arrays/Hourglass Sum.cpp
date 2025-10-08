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

    int32_t num[6][6];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cin >> num[i][j];
        }
    }

    int32_t tot; int32_t Max = INT32_MIN;
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            tot = num[i][j] + num[i-1][j] + num[i-1][j-1] + num[i-1][j+1] + num[i+1][j] + num[i+1][j-1] + num[i+1][j+1];
            Max = max(Max, tot);
        }
    }
    cout << Max << endl;


    return 0;
}