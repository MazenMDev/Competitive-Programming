#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int number;
    cin >> number;
    int one[8], two[8], save[8];
    for (int i = 0; i < number; i++) {
        cin >> one[i];
        save[i] = one[i];
    }
    for (int i = 0; i < number; i++) {
        cin >> two[i];
    }

    sort(save, save + number);
    int posone, postwo;
    int count = 1;
    do
    {
        bool checkone = true; bool checktwo = true;
        for (int i = 0; i < number; i++) {
            if (one[i] != save[i]) {
                checkone = false;
            }
            if (two[i] != save[i]) {
                checktwo = false;
            }
        }
        if (checkone) { posone = count; }
        if (checktwo) { postwo = count; }
        count++;
    } while (next_permutation(save, save + number));

    cout << abs(posone - postwo) << endl;
}