#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    char word[number];
    int count = 0;
    char prev;
    for(int i=0; i<number; i++){
        if (word[i] == prev)
        {
            count++;
        }
        prev = word[i];
    }
    cout << count << endl;
}