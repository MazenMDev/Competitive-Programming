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


//SayHelloToMyLittleFriend
//Say_Hello_To_My_Little_Friend
int32_t main(){
    fast_io();

    // we need to find 11 or have two that will give us 10 and 01
    // but the min
    int32_t number;
    cin >> number;
    while(number--){
        int32_t n;
        cin >> n;
        vector<int32_t>m(n);
        string s;
        int32_t mn = INT32_MAX; int32_t min = INT32_MAX; int32_t min1 = INT32_MAX;
        for(int i=0; i<n; i++){
            cin >> m[i];
            cin >> s;
            if(s[0] == '1' and s[1] == '1'){
                if(m[i] < mn) mn = m[i];
                continue;
            }
            if(s[0] == '1'){
                if(m[i] < min) min = m[i];
            }
            if(s[1] == '1'){
                if(m[i] < min1) min1 = m[i];
            }
        }
        if(mn == INT32_MAX and (min == INT32_MAX or min1 == INT32_MAX)){
            cout << -1 << endl;
            continue;
        }
        if(mn < (min + min1) or (min == INT32_MAX or min1 == INT32_MAX)){

            cout <<  mn << endl;
        }
        else cout << min + min1 << endl;

    }





    return 0;
}