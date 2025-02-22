#include <iostream>
using namespace std;
int main() {
	int w, h, x, y, r;
	cin >> w >> h >> x >> y >> r;
	int checky, checkx, checkx1, checky1;
	checky = x + r;
	checkx = y + r;
	checky1 = x - r;
	checkx1 = y - r;
	cout << checky << endl << checkx << endl;
	if (checky <= w && checkx <= h && checky1 >= 0 && checkx1 >= 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}
