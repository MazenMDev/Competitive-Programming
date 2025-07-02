#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int num;

    int count = 0;
    for (int i = 0; i < number; i++) {
        count = 0;
        cin >> num;
        int* days = new int[num];
        for (int j = 0; j < num; j++) {
            cin >> days[j];
        }
        for (int j = 0; j < num; j++) {
            for (int k = j; k < num; k++) {
                if (days[j] > days[k])
                {
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;
        delete[] days;
    }
}