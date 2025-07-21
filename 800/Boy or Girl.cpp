#include <iostream>
#include <set>
using namespace std;

int main() {
    string name;
    cin >> name;
    set<char>C;
    for (char ch : name) {
        C.insert(ch);
    }
    if (C.size() % 2 != 0) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
}