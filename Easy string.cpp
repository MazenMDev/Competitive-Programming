#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	int count;
	while (t--)
	{
		count = 0;
		string s;
		cin >> s;
		for (int i = 0; i <s.length(); i++) {
			if (s[i] == '1')
			{
				count++;
			}
		}
		cout << count << endl;
	}
}
