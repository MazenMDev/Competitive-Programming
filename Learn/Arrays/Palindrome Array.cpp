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
    vector<int32_t>num(number);
    for(int i=0; i<number; i++){
        cin >> num[i];
    }
    vector<int32_t>save;
    save = num;
    reverse(num.begin(), num.end());
    if(save == num){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;


    return 0;
}