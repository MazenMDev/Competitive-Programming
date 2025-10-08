#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int number;
    string st;
    unordered_map<string, int>save;
    while (cin >> number)
    {
        cin >> st;
        if(save.find(st) == save.end()){
            cout << "OK" << endl;
            save[st] = 0;
        }
        else{
            save[st]++;
            cout << st << save[st];
        }
    }
    
}