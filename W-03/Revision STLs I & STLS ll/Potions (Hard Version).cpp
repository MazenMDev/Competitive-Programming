#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int number;
    cin >> number;
    priority_queue< int, vector<int>, greater<int> > save;
    int num, count = 0;
    long long sum = 0;
    while (number--) {
        cin >> num;
        sum += num;
        save.push(num);
        count++;
        if (sum < 0) {
            sum -= save.top();
            save.pop();
            count--;
        }
    }
    cout << count << endl;
}