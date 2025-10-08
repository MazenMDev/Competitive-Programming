#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string name;
    cin >> name;
    set<int>st;
    for (auto k : name) {
        st.insert(k);
    }
    if (st.size() % 2 != 0) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
}