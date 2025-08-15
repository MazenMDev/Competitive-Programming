#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}


int32_t main(){
    fast_io();

    int32_t n, i;
    cin >> n >> i;
    if(n & (1 << i)) cout << "true" << endl;
    else cout << "false" << endl;


    return 0;
}