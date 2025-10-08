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

    //we need to make all the array == each other so we need a forumla like
    // b[i] = (n+1) - a[i]; --> this will make all the pairs equal each other

    int32_t number;
    cin >> number;
    while(number--){
        int32_t n;
        cin >> n;
        vector<int32_t>a(n);
        vector<int32_t>b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            b[i] = (n+1) - a[i];
        }
        for(int i=0; i<n; i++){
            cout << b[i] << " ";
        }
        cout << endl;
    }




    return 0;
}