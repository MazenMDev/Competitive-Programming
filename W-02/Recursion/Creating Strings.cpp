#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void per(set<string>& store, string word) {
    if (next_permutation(word.begin(), word.end())) {
        store.insert(word);
        per(store, word);

    }
}


int main() {
    string word;
    cin >> word;
    int i = 0;
    set<string>store;
    sort(word.begin(), word.end());
    store.insert(word);
    int ch = 0;
    per(store, word);
    cout << store.size() << endl;
    for (auto s : store) {
        cout << s << endl;
    }
}