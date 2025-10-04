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

    int32_t t;
    cin >> t;
    while (t--)
    {
        int32_t x, n;
        cin >> x >> n;
        if(n % 2 == 0){
            cout << 0 << endl;
        }
        else cout << x << endl;
    }
    
}