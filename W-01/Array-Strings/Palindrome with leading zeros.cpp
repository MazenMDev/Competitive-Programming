#include <iostream>
using namespace std;

int main(){
    string n;
    cin >> n;
    int i = n.length();
    int j = 0;
    int count = 0;
    while(true){
        if (n.length() % 2 != 0)
        {
            if (n[j] == n[i])
            {
                count++;
            }
            else{
                count = -1;
                break;
            }
        }
        else{
            n.push_back(0);
            if (n[j] == n[i])
            {
                count++;
            }
            else{
                count = -1;
                break;
            }
        }
    }
    if (count == -1)
    {
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}