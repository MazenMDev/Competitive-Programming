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
    int32_t n;
    while(number--){
        cin >> n;
        int32_t num[n];
        for(int i=0; i<n; i++){
            cin >> num[i];
        }
        int32_t count = 0; int32_t track;
        for(int i=0; i<n; i++){
            count++;
            track = num[i];
            for(int j=i+1; j<n; j++){
                if(num[j] > track) {
                    count++;
                    track = num[j];
                }
                else{
                    break;
                }
            }
        }

        cout << count << endl;
    }



    return 0;

}