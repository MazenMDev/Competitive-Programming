#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int k;
    cin >> k;
    int count = 0;
    for(int i=0; i<number; i++){
        int num;
        cin >> num;
        while(num != 0){
            int n = num % 10;
            num /= 10;
            if (n <= k)
            {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
}