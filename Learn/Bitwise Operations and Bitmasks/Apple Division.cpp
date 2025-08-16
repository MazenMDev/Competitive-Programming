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


    int32_t num[number];
    for(int i=0; i < number; i++){
        cin >> num[i];
    }


    int32_t sum1 = 0; int32_t sum2 = 0;
    int32_t diff = 0;
    int32_t mn = INT32_MAX;
    for(int mask = 0; mask <(1 << number) ; mask++){
        sum1 = 0; sum2 = 0;
        for(int j=0; j < number ;j++){
            if((mask >> j) & 1){
                sum1 += num[j];
            }
            else{
                sum2 += num[j];
            }
        }
        diff = abs(sum1 - sum2);
        mn = min(mn, diff);
    }

    cout << mn << endl;

    return 0;
}