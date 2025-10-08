#include <iostream>
using namespace std;

int main(){
    int number, re;
    cin >> number >> re;
    int*num = new int[number];
    for(int i=0; i<number; i++){
        cin >> num[i];
    }
    int count = 0;
    while(count != number){
        count = 0;
        for(int i=0; i<number; i++){
            if(num[i] <= re and num[i] != -1){
                num[i] = -1;
            }
            else{
                num[i] -= re;
            }
            if(num[i] == -1)count++;
        }
    }
}