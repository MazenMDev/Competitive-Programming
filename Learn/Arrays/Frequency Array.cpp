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


    int32_t number; int32_t n;
    cin >> number >> n;
    vector<int32_t> num(number);
    for (int i = 0; i < number; i++) {
        cin >> num[i];
    }


    vector<int32_t>freq(n+1, 0);
    for(int i=0; i<number; i++){
        freq[num[i]]++;
    }
    for(int i=1; i<=n ;i++){
        cout << freq[i] << endl;
    }




    return 0;

}