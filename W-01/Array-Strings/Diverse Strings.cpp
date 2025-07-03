#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int number;
    cin >> number;
    string word;
    int count = 0;
    for (int i = 0; i < number; i++) {
        count = 0;
        cin >> word;
        sort(word.begin(), word.end());
        for (int j = 0; j < word.length()-1; j++) {
            char temp = word[j] + 1;
            if (word[j + 1] == temp)
            {
                count++;
            }
            else break;
        }
        if (count == word.length() - 1)
        {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}