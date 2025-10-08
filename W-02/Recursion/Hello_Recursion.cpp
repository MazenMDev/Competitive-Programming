#include <iostream>
using namespace std;


void recursion(int n, int& tot) {
    if (n == 0) { return; }
    int num;
    cin >> num;
    tot += num;
    recursion(--n, tot);
}

void sum(int& count) {
    int n, tot = 0;
    cin >> n;
    recursion(n, tot);
    cout << "Case " << count << ": " << tot << endl;
}

int main() {
    int number, count = 1;
    cin >> number;
    while (number--) {
        sum(count);
        count++;
    }
}

