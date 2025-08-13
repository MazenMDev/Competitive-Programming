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

    int64_t number;
    cin >> number;
    stack<int64_t>store;
    int64_t num;
    for(int i=0; i<number; i++){
        cin >> num;
        store.push(num);
    }
    for(int i=0; i<number; i++){
        cout << store.top() << " ";
        store.pop();
    }
    return 0;

}