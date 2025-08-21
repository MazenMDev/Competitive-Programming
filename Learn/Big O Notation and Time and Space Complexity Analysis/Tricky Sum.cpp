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
//we need to make all power of 2 with minus (-)
//we will get the sum from 1 to n
//then - from 2*(sum of power of two until n) /// one for remove the power 2 numbers 
//and another for make them minus
    int32_t number;
    cin >> number;
    int32_t n;
    while(number--){
        cin >> n;
        int64_t sum = n * (n+1) / 2;
        int64_t sum2 = 0;
        for(int i=1; i<n; i*2){
            sum2 += i;
        }
        cout << sum - 2*(sum2) << endl;
    }




    return 0;
}