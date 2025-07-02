#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int number;
    cin >> number;
    int n, k;

    for (int i = 0; i < number; i++) {
        int count = 0;
        cin >> n >> k;
        int* arr1 = new int[n];
        int* arr2 = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr1[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> arr2[j];
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        reverse(arr2, arr2 + n);
        int j = 0;

        while (j < n) {
            if ((arr2[j] > arr1[j]) and (j < k))
            {
                swap(arr2[j], arr1[j]);
            }
            j++;
        }
        j = 0;
        while (j < n) {
            count += arr1[j];
            j++;
        }

        cout << count << endl;
    }
}