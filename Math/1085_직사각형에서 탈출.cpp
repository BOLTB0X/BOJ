#include <iostream>

using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int x, y, w, h;
	int xw = 0, yh = 0;

	cin >> x >> y >> w >> h;

	for (int i = x; i < w; ++i)
		xw++;
	for (int i = y; i < h; ++i)
		yh++;

	cout << Min(Min(x, y), Min(xw, yh));
	return 0;
}