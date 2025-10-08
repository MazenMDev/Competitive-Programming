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

    int32_t number;
    cin >> number;
    string num;
    while(number--){
        cin >> num;
        auto found = num.find("101");
        auto found2 = num.find("010");
        if(found != string::npos || found2 != string::npos){
            cout << "Good" << endl;
        }
        else cout << "Bad" << endl;
    }




    return 0;
}