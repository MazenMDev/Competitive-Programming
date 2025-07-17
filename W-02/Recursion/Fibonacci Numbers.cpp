#include <iostream>
using namespace std;


void fib(int& i, int num[], int& n) {
    if (n == 0) return;
    num[i + 2] = num[i] + num[i + 1];
    fib(++i, num, --n);
}

int main() {
    int number;
    cin >> number;
    int* num = new int[number + 2];
    num[0] = 0; 
    if(number > 0) num[1] = 1;
    int i = 0;
    int n = number;
    fib(i, num, n);
    cout << num[number] << endl;
}