#include <iostream>
using namespace std;
int main() {
	int X, Y;
	char dot;
	cin >> X >> dot >> Y;
	if (Y <= 2 && Y >= 0)
	{
		cout << X << "-" << endl;
	}
	else if (Y <= 6 && Y >= 3)
	{
		cout << X << endl;
	}
	else if (Y <= 9 && Y >= 7)
	{
		cout << X << "+" << endl;
	}
}
