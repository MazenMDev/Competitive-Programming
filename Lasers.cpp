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
    while(t--){
        int32_t n, m, x, y;
        cin >> n >> m >> x >> y;
        for(int i=0; i<n ;i++){
            int32_t a;
            cin >> a;
        }
        for(int i=0; i<m; i++){
            int32_t b;
            cin >> b;
        }

        cout << n + m << endl;
    }
}