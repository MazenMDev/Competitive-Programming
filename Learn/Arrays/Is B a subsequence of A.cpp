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

    int32_t n, m;
    cin >> n >> m;
    int32_t a[n]; int32_t b[m];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    int32_t track = 0; int32_t count = 0;
    for(int i=0; i<n; i++){
        if(a[i] == b[track] ){
            if (track < m -1) track++;
            count++;
        }
    }
    if(count == m){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    
    return 0;
}