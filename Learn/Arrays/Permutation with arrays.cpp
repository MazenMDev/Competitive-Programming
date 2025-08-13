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
    int32_t num1[number];
    int32_t num2[number];
    for(int i=0; i<number; i++){
        cin >> num1[i];
    }
    for(int i=0; i<number; i++){
        cin >> num2[i];
    }
    sort(num1, num1 + number);
    sort(num2, num2 + number);
    for(int i=0; i<number; i++){
        if(num1[i] != num2[i]){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;



    return 0;

}