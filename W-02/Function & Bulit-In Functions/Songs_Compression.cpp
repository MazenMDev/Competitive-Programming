#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int number, c;
    cin >> number >> c;

    int* original = new int[number];
    int* compressed = new int[number];
    int* save = new int[number];

    long long sum_original = 0;
    long long sum_compressed = 0;

    for (int i = 0; i < number; i++) {
        cin >> original[i] >> compressed[i];
        sum_original += original[i];
        sum_compressed += compressed[i];
        save[i] = original[i] - compressed[i];
    }

    if (sum_compressed > c) {
        cout << -1 << endl;
        return 0;
    }

    if (sum_original <= c) {
        cout << 0 << endl;
        return 0;
    }

    sort(save, save + number, greater<int>());

    int count = 0;
    for (int i = 0; i < number && sum_original > c; i++) {
        sum_original -= save[i];
        count++;
    }

    cout << count << endl;

    delete[] original;
    delete[] compressed;
    delete[] save;

    return 0;
}
