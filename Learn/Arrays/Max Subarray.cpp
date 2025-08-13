#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}


int32_t main(){
    int32_t number;
    cin >> number;

    int32_t n;
    while(number--){
        cin >> n;
        int32_t num[n];
        for(int i=0; i<n; i++){
            cin >> num[i];
        }
        int32_t M;
        for(int i=0; i<n; i++){
            M = num[i];
            cout << M << " ";
            for(int j=i+1; j<n; j++){
                M = max(M, num[j]);
                cout << M << endl;
            }
        }
        cout << endl;
    }
    


    return 0;
}