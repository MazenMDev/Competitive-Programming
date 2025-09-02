#include <bits/stdc++.h>
#define endl "\n"
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

    int64_t number;
    cin >> number;
    bool check = true;
    if(number % 2 != 0){
        number++;
        check = false;
    }
    if(check) cout << number / 2 << endl;
    else cout << "-" << number/2 << endl;



    return 0;
}