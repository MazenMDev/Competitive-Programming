#include <iostream> 
using namespace std;

int main() {
    string one, two;
    cin >> one >> two;
    for (int i = 0; i < one.length(); i++) {
        one[i] = tolower(one[i]); two[i] =tolower(two[i]);
        if (one[i] == two[i]) continue;
        else if (one[i] > two[i]) {
            cout << 1 << endl;
            return 0;
        }
        else if (one[i] < two[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}