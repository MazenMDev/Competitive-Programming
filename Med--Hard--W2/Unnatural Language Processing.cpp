#include <iostream>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'o' || c == 'u' || c == 'e' || c == 'i';
}

int main() {
    int N;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int k = 0; k < s.length(); k++) {
            bool validNext = (k + 1 < s.length()); 
            bool validPrev = (k - 1 >= 0);         
            if (isVowel(s[k]))
            {
                cout << s[k];
            }
            else
            {
                if (validNext && validPrev && isVowel(s[k + 1]) && isVowel(s[k - 1]))
                {
                    cout << ".";
                    cout << s[k];
                }
                else if (validPrev && !isVowel(s[k - 1]))
                {
                    cout << ".";
                    cout << s[k];
                }
                else {
                    cout << s[k];
                }
            }
        }
        cout << endl;
    }
}
