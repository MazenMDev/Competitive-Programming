#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void bubble_sort(vector<int32_t>& arr, int n) {
  for (int32_t i = 0; i < n - 1; i++) {
    for (int32_t j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int32_t main(){
    fast_io();

    int32_t number;
    cin >> number;
    vector<int32_t> arr(number, 0);

    for(int32_t i=0; i<number; i++){
        arr[i] = number - i;
    }
    auto start_time = clock();
    // sort(arr.begin(), arr.end());
    bubble_sort(arr, number);
    auto end_time = clock();

    cout << "Time taken to sort the array: " << end_time - start_time << " clock ticks\n";




    return 0;
}