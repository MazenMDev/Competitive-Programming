#include <bits/stdc++.h>
using namespace std;

int32_t maiN(){
    int32_t num, number;
    cin >> num >> number;
    int32_t tot = 0;
    tot += (pow(num, 0) - 1);
    int32_t k = 2;
    while(k <= number){
        tot += pow(num, k);
        k+=2;
    }
    cout << tot << "\n";

    return 0;
}