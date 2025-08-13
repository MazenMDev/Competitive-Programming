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
    int32_t min = 0; int32_t max = 0;
    for(int i=0; i<number; i++){
        cin >> num[i];
        if(num[min] > num[i]) min = i;
        if(num[max] < num[i]) max = i;
    }
    swap(num[min], num[max]);
    for(int i=0; i<number; i++){
        cout << num[i] << " ";
    }
    cout << endl;




    return 0;

}