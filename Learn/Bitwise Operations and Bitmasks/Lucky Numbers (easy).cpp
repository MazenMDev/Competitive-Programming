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

    string number;
    cin >> number;
    long long n = stoll(number);
    string s = "";

    long long mx = LLONG_MAX;
    int len = number.size();
    if(len % 2 != 0) len++;

    while(true){
        int32_t count7 = 0; int32_t count4 = 0;
        for(long long mask = 0; mask < (1LL << len); mask++){
            count7 = 0; count4 = 0;
            s = "";
            for(int j = 0; j < len; j++){
                
                uint32_t bit = (mask >> j) & 1;
                if(bit == 1){
                    s += '7';
                    count7++;
                }
                else{
                    s+= '4';
                    count4++;
                }
            }
            if(count4 == count7){
                long long val = stoll(s);
                if (val >= n) {
                    mx = min(mx, val);
                }
            }
        }
        if (mx != LLONG_MAX) {
            cout << mx << "\n"; 
            return 0;           
        }

        len+=2;
    }



    return 0;
}