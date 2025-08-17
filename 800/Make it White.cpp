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

    /*
    we need to pos of the first b and last pos of b
    then we will (pos2 - pos1) + 1
    */

    int32_t number;
    cin >> number;
    while(number--){
        int32_t n;
        cin >> n;
        string s;
        cin >> s;
        int32_t pos1 = -1; int32_t pos2 = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'B' and pos1 == -1) pos1 = i;
            if(s[i] == 'B') pos2 = i;
        }
        cout << (pos2 - pos1) + 1 << endl;
    }



    return 0;
}