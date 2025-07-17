#include <iostream>
using namespace std;

void remove(int& n, int num[], int& i, int x, int& count) {
    if (n == 0) return;
    cin >> num[i];
    if (num[i] == x) { i--; count++; }
    remove(--n, num, ++i, x, count);

}

int main() {
    int n;
    cin >> n;
    int number = n;
    int x, i = 0; 
    int count = 0;
    cin >> x;
    int* num = new int[n];
    remove(n, num, i, x, count);
    for (int k = 0; k < number - count; k++) {
        cout << num[k] << " ";
    }
}