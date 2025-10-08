#include <iostream>
#include <deque>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int number;
    cin >> number;
    string st;
    deque<string>save;
    int count = 0;
    while (number--) {
        cin >> st;
        string target = st;
        auto it = find(save.begin(), save.end(), target);
        if(it != save.end()){
            save.erase(it);
        }
        save.push_back(st);
    }
    for(int i=save.size()-1; i>=0; i--) {
        cout << save[i] << endl;
    }

}