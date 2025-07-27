// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//     string st;
//     stack<char>save;
//     cin >> st;
//     bool check = true;
//     for(int i=0; i<st.size(); i++){
//         save.push(st[i]);
//         if(i > 1){
//             if(st[i] == save.top()){
//                 save.pop();
//             }
//             else{
//                 cout << "NO\n";
//                 return 0;
//             }
//         }
//     }
//     if(check and save.empty()) {
//         cout << "YES\n";
//     } else {
//         cout << "NO\n";
//     }
// }