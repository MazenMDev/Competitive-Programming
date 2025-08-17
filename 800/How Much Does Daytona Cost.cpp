#include <bits/stdc++.h>
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

    while(number--){
        int32_t n, k;
        cin >> n >> k;

        bool check = false;
        vector<int32_t>num(n);
        for(int i=0; i<n; i++){
            cin >> num[i];
        }
        for(int i=0; i<n ;i++){
            if(num[i] == k){
                cout << "Yes" << endl;
                check = true;
                break;
            }
        }
        if(!check) cout << "No" << endl;
    }


    return 0;
}