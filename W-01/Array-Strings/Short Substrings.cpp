#include <iostream>
using namespace std;

int main(){
    int number; 
    cin >> number;
    string word;
    string a;
    int i=1;
    for(int i=0; i<number; i++){
        cin >> word;
        i = 1;
        a += word[0];
        for (int i = 1; i < word.length(); i += 2) {
            a += word[i];
        }
        cout << a << endl;
    }
}