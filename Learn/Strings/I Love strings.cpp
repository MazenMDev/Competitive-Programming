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
    string s, t;
    while(number--){
        cin >> s >> t;
        if(s.size() > t.size()) {
            for(int i=0; i<s.size(); i++){
                cout << s[i];
                if(t.size() > i){
                    cout << t[i];
                }
            }
        }
        else {
            for(int i=0; i<t.size(); i++){
                if (s.size() > i) cout << s[i];
                cout << t[i];
            }
        }
        cout << endl;
    }




    return 0;
}