#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	long long x1, y1, r1, x2, y2, r2;

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	long long x = abs(x1 - x2);
	long long y = abs(y1 - y2);

	if ((r1 + r2) * (r1 + r2) > pow(x,2) + pow(y,2))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}