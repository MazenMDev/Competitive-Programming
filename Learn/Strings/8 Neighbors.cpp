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

    int32_t r, c;
    cin >> r >> c;
    char w[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> w[i][j];
        }
    }
    int32_t x, y;
    cin >> x >> y;
    x--;
    y--;
    for(int i = x - 1; i <= x + 1 ; i++){
        for(int j = y - 1 ; j <= y + 1 ; j++){
            if(i == x and j == y) continue;
            else if(i < r and j < c and i >= 0 and j >= 0){
                if(w[i][j] != 'x'){
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}