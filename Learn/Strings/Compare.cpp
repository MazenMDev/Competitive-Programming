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

    string w1, w2;
    cin >> w1 >> w2;
    for(int i=0; i<w1.size(); i++){
        if(w1[i] > w2[i]){
            cout << w2 << endl;
            return 0;
        }
        else if(w2[i] > w1[i]){
            cout << w1 << endl;
            return 0;
        }
    }
    cout << w1 << endl;




    return 0;
}