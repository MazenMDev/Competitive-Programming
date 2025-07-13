#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    string word;
    while (number--) {
        cin >> word;
        if (word.length() <= 10) cout << word << endl;
        else {
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
        }
    }
}