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
    int32_t n, k;
    while(t--){
        cin >> n >> k;
        int32_t max = INT32_MIN;
        int32_t save;
        for(int i=1; i<= n; i++){
            for(int j=i+1; j<=n; j++){
                save = (i & j);
                if (save > max and save < k) max = save;
            }
        }
        cout << max << endl;
    }


    return 0;
}