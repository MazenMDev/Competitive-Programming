// #include <iostream>
// #include <deque>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//     int number;
//     cin >> number;
//     string st;
//     bool check;
//     while (number--)
//     {
//         cin >> st;
//         check = true;
//         int save = st.size() / 2;
//         for (int i = 0; i < save ; i++) {

//             if (*st.begin() == '{' and st[st.size()-1] == '}') {
//             }
//             else if (*st.begin() == '(' and st[st.size()-1] == ')') {
//             }
//             else if (*st.begin() == '[' and st[st.size()-1] == ']') {
//             }
//             else {
//                 cout << "NO\n";
//                 check = false;
//                 break;
//             }
//             st.erase(st.begin());
//             st.pop_back();
//         }
//         if (check) cout << "YES\n";
//     }
// }