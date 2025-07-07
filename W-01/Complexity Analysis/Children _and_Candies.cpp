#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;

    int sum = 0;
    for(int i=0; i<number; i++){
        sum += i;
    }
    cout << sum << endl;
}