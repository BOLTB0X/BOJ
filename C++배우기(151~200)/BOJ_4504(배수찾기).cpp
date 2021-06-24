#include <iostream>
using namespace std;

int main() {
	int n,value;
	cin >> n;
	while (true) {
		cin >> value;
		if (value == 0) break;
		else {
			if (value % n == 0) {
				printf("%d is a multiple of %d.\n", value, n);
			}
			else printf("%d is NOT a multiple of %d.\n", value, n);
		}
	}
}