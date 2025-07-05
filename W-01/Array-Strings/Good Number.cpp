#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int k;
    cin >> k;
    int ans = 0;
    while(number--){
        string num;
        cin >> num;
        bool valid = true;
        for(int i=0 ;i<=k ;i++){
            char tochar = i + 48;
            if(num.find(tochar) == -1){
                valid = false;
                break;
            }
        }
        if (valid)
        {
            ans++;
        }
    }
    cout << ans << endl;
}