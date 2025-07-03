#include <iostream>
#include <string>
#include <set>
using  namespace std;

int main() {
    string let;
    getline(cin, let);
    set<char>letters;
    for (int i = 0; i < (int)let.length(); i++) {
        if (let[i] != '{' and let[i] != '}' and let[i] != ',' and let[i] != ' ')
        {
            char c = let[i];
            letters.insert(c);
        }
    }
    cout << (int)letters.size() << endl;
}