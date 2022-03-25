#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	//a^2 - b^2 = (T/2)^2
	double half = (double)T / 2.0;
	int result = (int)(half * half + 0.5);
	cout << result;
	return 0;
}