#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}


int32_t main(){
    fast_io();

    int32_t n, k;
    cin >> n >> k;
    int32_t one, two, three;
    int32_t maxone = INT32_MIN; int32_t maxtwo = INT32_MIN; int32_t maxthree = INT32_MIN;

    for(int i=1; i<=n ;i++){
        for(int j=i+1; j<=n ;j++){
            one = i & j;
            two = i | j;
            three = i ^ j;
            if(maxone < one and one < k) maxone = one;
            if(maxtwo < two and two < k) maxtwo = two;
            if(maxthree < three and three < k) maxthree = three;
        }
    }
    cout << maxone << endl << maxtwo << endl << maxthree << endl;


    return 0;
}