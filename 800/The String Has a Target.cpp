#include <bits/stdc++.h>
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

    //search for the last a and move it to the begining
    // if a not found move to the next char is b and so on

    int32_t number;
    cin >> number;
    while(number--){
        int32_t n; cin >> n;
        string s; cin >> s;
        bool found = false;
        char ch = 'a';
        int32_t pos = -1;
        while(!found){
            for(int i=0; i<n; i++){
                if(s[i] == ch){
                    found = true;
                    pos = i;
                }
            }
            if(found){
                s.insert(0, 1, ch);
                s.erase(pos+1, 1);
            }
            else{
                ch++;
            }
        }
        cout << s << endl;
    }





    return 0;
}