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
        int32_t n, m;
        cin >> n >> m;

        int32_t tracka = 0;
        int32_t trackb = 0;
        int32_t gap;
        int32_t score;
        for(int i=0; i<n; i++){
            int32_t a, b;
            cin >> a >> b;
            gap = (tracka - a);
            if((trackb + gap) % 2 != b) gap--;
            score = gap;
            tracka = a;
            trackb = b;
        }
        cout << score << endl;
    }
}