#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int main() {
    fast_io();


    int64_t number;
    cin >> number;

    for(int i=1; i<=number; i++){
        cout << string(number-i, ' ') << string(i*2 - 1, '*') << endl;
    }
    for(int i=number; i>0; i--){
        cout << string(number-i, ' ') << string(2*i - 1, '*') << endl;
    }
}