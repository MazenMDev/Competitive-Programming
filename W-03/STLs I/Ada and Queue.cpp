#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int main() {
    int number;
    cin >> number;
    cin.ignore();
    deque<int> save;
    string order, line;
    int num;
    bool reversed = false;
    for (int i = 0; i < number; i++) {
        getline(cin, order);
        if (order.find("toFront") != string::npos) {
            stringstream ss(order);
            ss >> line >> num;
            if (!reversed) save.push_front(num);
            else save.push_back(num);
        }
        else if (order.find("push_back") != string::npos) {
            stringstream ss(order);
            ss >> line >> num;
            if (!reversed) save.push_back(num);
            else save.push_front(num);
        }
        else if (order.find("front") != string::npos) {
            if (save.empty()) cout << "No job for Ada?" << endl;
            else {
                if (!reversed) {
                    cout << save.front() << endl;
                    save.pop_front();
                } else {
                    cout << save.back() << endl;
                    save.pop_back();
                }
            }
        }
        else if (order.find("back") != string::npos) {
            if (save.empty()) cout << "No job for Ada?" << endl;
            else {
                if (!reversed) {
                    cout << save.back() << endl;
                    save.pop_back();
                } else {
                    cout << save.front() << endl;
                    save.pop_front();
                }
            }
        }
        else if (order.find("reverse") != string::npos) {
            reversed = !reversed;
        }
    }
}
