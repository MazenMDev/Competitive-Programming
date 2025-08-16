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

    string number;
    cin >> number;
    string save = number;

    long long tot = 0;
    for(int mask = 0; mask < (1 << (number.size()-1)); mask++){
        int k = 0;
        for(int j=0; j < number.size()-1; j++){
            if((mask >> j) & 1){
                number.insert(j+1+k, 1, '+');
                k++;
            }
        }

        string s = "";
        long long sum = 0;
        for(int i=0; i<number.size(); i++){
            if(number[i] == '+'){
                long long num = stoll(s);
                sum += num;
                s = "";
            } else {
                s += number[i];
            }
        }
        sum += stoll(s); 
        tot += sum;
        number = save;
    }

    cout << tot << endl;


    return 0;
}