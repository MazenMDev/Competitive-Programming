#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

void checklucky(int num, bool& check){
    int64_t save;
    int64_t lucky = num;
    bool found = true;
    while(num != 0){
        save = num % 10;
        if(save != 7 and save != 4){
            found = false;
            break;
        }
        num /= 10;
    }
    if(found){
        check = true;
        cout << lucky <<  " ";
    }
}

int main() {
    fast_io();

    int64_t number1, number2;
    cin >> number1 >> number2;
    bool check = false;
    for(int i=number1; i<=number2; i++){
        checklucky(i, check);
    }
    if(!check){
        cout << -1 << endl;
    }

    return 0;
}