#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    int number;
    cin >> number;
    int num;
    string ls;

    while (number--) {
        cin >> num;
        cin >> ls;
        int min = 1;
        int max = num;
        int* stick = new int[num];
        for (int i = ls.length() - 1; i >= 0; i--) {
            if (ls[i] == '<') {
                stick[i + 1] = min;
                min++;
            }
            else {
                stick[i + 1] = max;
                max--;
            }
        }
        if (ls[0] == '<') stick[0] = max;
        else stick[0] = min;
        for (int i = 0; i < ls.length()+1; i++) {
            cout << stick[i] << " ";
        }
        cout << endl;
    }
}