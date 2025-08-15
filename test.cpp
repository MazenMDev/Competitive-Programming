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

    int32_t number;
    cin >> number;
    int32_t n;
    uint64_t num;
    while(number--){
        cin >> n >> num;
        bool check = true;
        bool done = false;
        int64_t count = 0;
        if(num <= 8){
            count +=2;
            if(count >= n){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else{
            for(int track = 8; track < num; track++){
                check = true;
                for(int i=0; i<64; i+=2){
                    uint64_t bit1 = (track >> i) & 1;
                    uint64_t bit2 = (track >> (i+1)) & 1;
                    cout << "bit1 " << bit1 << endl;
                    cout << "bit2 " << bit2 << endl;
                    if(bit1 == bit2){
                        check = false;
                        break;
                    }
                }
                cout << endl << endl;
                if(check) count++;
                if(count == n){
                    cout << "YES" << endl;
                    done = true;
                    break;
                }
            }
            if(!done) cout << "NO" << endl;
        }
    }
        
        
        return 0;
}