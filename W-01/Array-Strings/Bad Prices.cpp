#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int num;
    int min;
    int count = 0;
    while(number--){
        cin >> num;
        int* day = new int[num];
        for(int i=0; i<num; i++){
            cin >> day[i];
        }
        min = 1000001;
        count = 0;
        for (int i = num - 1; i >= 0; i--) {
            if (day[i] > min) {
                count++;
            } else {
                min = day[i];
            }
        }
        cout << count << endl;
        delete[] day;  
    }
}