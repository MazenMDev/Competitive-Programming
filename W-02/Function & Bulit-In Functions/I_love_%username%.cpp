#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int*num = new int[number];
    for(int i=0; i<number; i++){
        cin >> num[i];
    }
    int count = 0;
    int max = -999;
    int min = 999;
    for(int i=1; i<number; i++){
        if (num[i] > num[0] and num[i] > max)
        {
            count++;
            max = num[i];
        }
        if (num[i] < num[0] and num[i] < min)
        {
            count++;
            min = num[i];
        }
    }
    cout << count << endl;
}