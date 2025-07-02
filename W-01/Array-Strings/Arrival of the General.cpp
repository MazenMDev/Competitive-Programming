#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int max = -999;
    int min = 999;
    int posmax, posmin;
    int* height = new int[number];
    int count = 0;
    for (int i = 0; i < number; i++) {
        cin >> height[i];
        if (max < height[i]) { max = height[i]; posmax = i; }
        if (min > height[i] || min == height[i]) { min = height[i]; posmin = i; }
    }
    while (posmax > 0) {
        swap(height[posmax - 1], height[posmax]);
        if ((posmax-1) == posmin)
        {
            posmin++;
        }
        count++;
        posmax--;
    }
    while (posmin < number - 1) {
        swap(height[posmin], height[posmin + 1]);
        count++;
        posmin++;
    }
    cout << count << endl;
}