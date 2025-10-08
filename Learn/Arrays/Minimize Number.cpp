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
    int32_t num[number];
    int32_t count = 0;
    for(int i=0; i<number; i++){
        cin >> num[i];
        if(num[i] % 2 == 0) count++;
    }
    if(count != number){
        cout << 0 << endl;
        return 0;
    }
    int32_t op = 0;
    while(true){
        for(int i=0; i<number; i++){
            if(num[i] % 2 == 0) num[i] /= 2;
            else{
                cout << op << endl;
                return 0;
            }
        }
        op++;
    }

    return 0;

}