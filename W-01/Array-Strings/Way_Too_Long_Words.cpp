#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    string word;
    for (int i = 0; i < number; i++) {
        cin >> word;
        if (word.length() <= 10)
        {
            cout << word << endl;
        }
        else {
            int st = word.length();
            cout << word[0] << word.length() - 2 << word[st - 1] << endl;
        }
    }
}