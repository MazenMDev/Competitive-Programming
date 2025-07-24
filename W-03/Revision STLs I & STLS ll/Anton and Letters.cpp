#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    string line;
    getline(cin, line);
    set<char>let;
    for(auto c:line){
        let.insert(c);
    }

    cout << let.size() << endl;
}