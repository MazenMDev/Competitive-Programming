#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string st;
    cin >> st;
    sort(st.begin(), st.end());
    for(int i=0; i<st.length(); i++){
        if(i == st.length()-1) {cout << st[i]; break;}
        if(st[i] != '+'){
            cout << st[i] << "+";
        }
    }
}