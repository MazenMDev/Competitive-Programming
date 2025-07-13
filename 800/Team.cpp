#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int fri[3];
    int all = 0;
    for(int i=0; i<number; i++){
        int count = 0;
        for(int j=0; j<3; j++){
            cin >> fri[j];
            if(fri[j] == 1) count++;
        }
        if(count >= 2) all++;
    }
    cout << all << endl;
}