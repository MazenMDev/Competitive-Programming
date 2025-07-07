#include <iostream>
using namespace std;

int main(){
    long long number;
    cin >> number;
    long long count = 0;
    count = (number+1) / 2;
    if (number % 2 == 0)
    {
        cout << count << endl;
    }
    else cout << "-" << count << endl;
    
}