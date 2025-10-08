#include <iostream>
using namespace std;

void check(int& i, string word, int& ch) {
    if (i == word.length()) return;
    if ((i % 2 == 0) and isupper(word[i])) { ch = 0; return; }
    if ((i % 2 != 0) and islower(word[i])) { ch = 0; return; }
    check(++i, word, ch);
}

int main() {
    string word;
    cin >> word;
    int i = 0;
    int ch = 1;
    check(i, word, ch);
    if (ch == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}