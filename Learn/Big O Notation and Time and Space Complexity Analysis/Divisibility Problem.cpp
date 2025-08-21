#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main(){
    fast_io();

    int32_t number;
    cin >> number;
    int32_t a, b;
    while(number--){
        cin >> a >> b;
        if(a % b == 0) {
            cout << 0 << endl;
            continue;
        }
        if(a < b) {
            cout << b - a << endl;
            continue;
        }
        else{
            cout << b - a % b << endl;
        }
    }

    return 0;
}