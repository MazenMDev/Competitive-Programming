#include <iostream>
using namespace std;

int main(){
    int number;
    cin >>number;
    string dir;
    cin >> dir;
    bool check = false;

    int*num = new int[number];
    for(int i=0; i<number; i++){
        cin >> num[i];
    }
    bool checkl = false; bool checkr = false;
    if (dir.find('L') != string::npos) checkl = true;
    if (dir.find('R') != string::npos) checkr = true;
    if (!checkl or !checkr) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < dir.size()-1; i++) {
        if (dir[i] == 'R' and dir[i + 1] == 'L') {
            check = true;
            break;
        }
    }
    if (!check) {
        cout << -1 << endl;
        return 0;
    }
    int count = 0;
    int last = -1;
    while(true){
        count++;
        for(int i=0; i<number; i++){
            if(dir[i] == 'R') num[i]++;
            else num[i]--;
            if(last == num[i]){
                cout << count << endl;
                return 0;
            }
            last = num[i];
        }
    }
}