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
    string s;
    cin >> s;
    int32_t countr = 0; int32_t countb = 0; int32_t countg = 0;
    int32_t mn = INT32_MAX;
    for(int i=0; i<number; i++){
        if(s[i] == s[i+1] and s[i] == 'R') countr++;
        if(s[i] == s[i+1] and s[i] == 'G') countg++;
        if(s[i] == s[i+1] and s[i] == 'B') countb++;
    }


    cout << countr + countb + countg << endl;



    return 0;
}