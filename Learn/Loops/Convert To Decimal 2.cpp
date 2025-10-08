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
    while(number--){
        int32_t num;
        cin >> num;

        int64_t count = 0; int64_t tot = 0;
        while(num != 0){
            if(num % 2 != 0){
                count++;
            }
            num /= 2;
        }
        for(int i=0; i<count; i++){
            tot += pow(2, i);
        }
        cout << tot << endl;
    }

    return 0;
}