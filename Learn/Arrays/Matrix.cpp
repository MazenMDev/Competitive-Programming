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
    int32_t num[number][number];
    int32_t k = 0;
    int32_t r = 0; int32_t c = number-1 ;
    int32_t tot1 = 0; int32_t tot2 = 0;
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            cin >> num[i][j];
        }
    }

    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            if(k == i and k == j) {
                tot1 += num[i][j];
                k++;
            }
            if(r == i and c == j){
                tot2 += num[i][j];
                if (r < number-1) {
                    r++; c--;
                }
            }
        }
    }

    cout << abs(tot1 - tot2) << endl;



    return 0;
}