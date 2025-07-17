// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int number;
//     cin >> number;
//     cin.ignore();
//     string num;
//     getline(cin, num); 

//     char max = '0';
//     char min = '9';

//     for (char ch : num) {
//         if (ch >= '0' && ch <= '9') { 
//             if (ch > max) max = ch;
//             if (ch < min) min = ch;
//         }
//     }
//     int first = (max -'0') + (min-'0');
//     int i = 0;
//     int second = 0;
//     for (char save : num) {

//         if ((num[i] != max) and (num[i] != min) and (num[i] != ' ')) {
//             second += (save - '0');
//         }
//         i++;
//     }
//     cout << abs(first - second);
// }