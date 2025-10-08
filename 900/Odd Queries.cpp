// #include <iostream>
// #include <deque>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//     int number;
//     cin >> number;
//     while (number--) {
//         int sum = 0;
//         int numar, op;
//         int l, r, n;
//         cin >> numar >> op;
//         deque<int>num(numar);
//         for (int i = 0; i < numar; i++) {
//             cin >> num[i];
//         }
//         int count;
//         while (op--)
//         {
//             sum = 0;
//             cin >> l >> r >> n;
//             count = r - l;
//             count++;
//             for (int i = 0; i < l-1; i++) {
//                 sum += num[i];
//             }
//             for (int i = r; i < numar; i++) {
//                 sum += num[i];
//             }
//             int tot = count * n;
//             sum += tot;
//             if (sum % 2 != 0) {
//                 cout << "YES\n";
//             }
//             else {
//                 cout << "NO\n";
//             }
//         }
//     }
// }