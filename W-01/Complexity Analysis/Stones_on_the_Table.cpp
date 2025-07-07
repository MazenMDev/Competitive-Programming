#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    string stone;
    cin >> stone;
    int count = 0;
    for(int i=0 ;i<number-1; i++){
        if (stone[i] == stone[i+1])
        {
            count++;
        }
    }
    cout << count << endl;
}