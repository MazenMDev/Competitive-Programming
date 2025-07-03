#include <iostream>
using namespace std;

int main() {
	string number;
	cin >> number;

	int check = 1;
	while (!number.empty() and number.back() == '0') {
		number.pop_back();
	}
	int i = (int)number.length() - 1;
	int j = 0;
	while (j < i) {
		if (number[j] != number[i])
		{
			check = 0;
			break;
		}
		j++; i--;
	}
	if (check)
	{
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}