#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int*num = new int[number];
    int check = -1;
    for(int i=0; i<number; i++){
        cin >> num[i];
        if (num[i] == 1)
        {
            check = 1;
            break;
        }
    }
    if(check == 1){cout << -1 << endl;}
    else{
        cout << 1 << endl;
    }
}