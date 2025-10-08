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

    int32_t number;
    cin >> number;
    while (number--)
    {
        vector<int32_t>save(3);
        cin >> save[0] >> save[1] >> save[2];
        for(int i=0; i<5; i++){
            (*min_element(save.begin(), save.end()))++;
        }
        cout << save[0] * save[1] * save[2] << endl;
    }






    return 0;
}