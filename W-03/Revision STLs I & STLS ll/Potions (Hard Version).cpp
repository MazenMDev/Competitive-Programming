// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     int number;
//     cin >> number;
//     int save = number;
//     int* num = new int[number];
//     int i = 0;
//     while (save--) {
//         cin >> num[i++];
//     }
//     sort(num, num + number);
//     reverse(num, num + number);
//     int sum = 0; int count = 0;
//     for (int i = 0; i < number; i++) {
//         sum += num[i];
//         count++;
//         if (sum < 0) { 
//             sum -= num[i];
//             cout << --count << endl;
//             return 0;
//         }
//     }
//     cout << count << endl;
// }