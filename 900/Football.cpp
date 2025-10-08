#include <iostream>
using namespace std;

int main() {
	string number;
	cin >> number;
	int count1 = 0; int count0 = 0;
	for (int i = 0; i < number.size(); i++) {
		if (number[i] == '1') {
			count0 = 0;
			count1++;
		}
		else {
			count1 = 0;
			count0++;
		}
		if (count1 == 7 or count0 == 7) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}