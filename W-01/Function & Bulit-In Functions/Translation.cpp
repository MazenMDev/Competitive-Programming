#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string word1, word2;
    cin >> word1 >> word2;
    
    if (word1.length() != word2.length()) {
        cout << "No" << endl;
        return 0;
    }

    int check = -1;
    reverse(word2.begin(), word2.end());
    for(int i=0; i<word1.length(); i++){
        if (word1[i] != word2[i])
        {
            check = 0;
            break;
        }
    }
    if(check == 0){cout << "No" << endl;}
    else cout << "Yes" << endl;
}