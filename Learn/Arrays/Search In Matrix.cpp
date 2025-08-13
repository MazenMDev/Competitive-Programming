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


    int32_t n,m;
    cin >> n >> m;
    int32_t num[n][m];
    for(int i=0; i<n ;i++){
        for(int j=0 ; j<m ;j++){
            cin >> num[i][j];
        }
    }
    int32_t x;
    cin >> x;
    for(int i=0; i<n ;i++){
        for(int j=0 ; j<m ;j++){
            if(num[i][j] == x){
                cout << "will not take number" << endl;
                return 0;
            }
        }
    }

    cout << "will take number" << endl;


    return 0;
}