#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> pos, neg, zero;
    int number;
    cin >> number;
    for(int i=0; i<number; i++){
        int x;
        cin >> x;
        if(x < 0) neg.push_back(x);
        else if(x > 0) pos.push_back(x);
        else if(x == 0)zero.push_back(x);
    }
    if(pos.size() == 0){
        pos.push_back(neg[neg.size() - 1]);
        pos.push_back(neg[neg.size() - 2]);
        neg.pop_back();
        neg.pop_back();
    }
    if(neg.size() % 2 == 0){
        zero.push_back(neg[neg.size() - 1]);
        neg.pop_back();
    }
    cout << neg.size() << " ";
    for(int i=0; i<neg.size(); i++){
        cout << neg[i] << " ";
    }
    cout << endl;
    cout << pos.size() << " ";
    for(int i=0; i<pos.size(); i++){
        cout << pos[i] << " ";
    }
    cout << endl;
    cout << zero.size() << " ";
    for(int i=0; i<zero.size(); i++){
        cout << zero[i] << " ";
    }

    return 0;
}