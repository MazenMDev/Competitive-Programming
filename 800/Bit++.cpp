#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    string op;
    int count = 0;
    for(int i=0; i<number; i++){
        cin >> op;
        if(op == "++X" || op == "X++") count++;
        else if(op == "--X" || op == "X--") count--;
    }
    cout << count << endl;
}