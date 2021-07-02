#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> arr;
int n;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		arr.insert(value);
	}

	for (auto i:arr) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}
