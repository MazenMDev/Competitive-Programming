#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int number;
    cin >> number;
    int*num = new int [number];
    for(int i=0; i<number; i++) 
    {
        cin >> num[i];
    }
    sort(num,num+number);
    for(int i=0; i<number; i++) 
    {
        cout << num[i] << " ";
    }
}