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
    int32_t num[number];
    for(int i=0; i<number; i++){
        cin >> num[i];
    }

    int32_t sum = 0;
    int32_t track = 2;
    for(int i=0; i< (1 << number); i++){
        int sum = 0;
        for(int j=0; j<number; j++){
            if( (i >> j) & 1 ) sum += num[j];
            else sum -= num[j];
        }
        if(sum % 360 == 0){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";


    return 0;
}