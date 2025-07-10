#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int*num = new int[number];
    int max = -999999;
    int posmax,posmin;
    int min = 9999999;
    for(int i=0; i<number; i++){
        cin >> num[i];
        if(max < num[i]){max = num[i]; posmax = i;}
        if(min > num[i]){min = num[i]; posmin = i;}
    }

    int count = 0;
    while(num[0] != max)
    {
        count++;
        swap(num[posmax],num[posmax-1]);
        if(num[posmax-1] == posmin){
            posmin == posmax;
        }
        posmax--;
    }

    while(num[number-1] != min){
        count++;
        swap(num[posmin], num[posmin+1]);
        posmin++;
    }
    cout << count << endl;
}