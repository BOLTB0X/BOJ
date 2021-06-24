#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,value,max_value,idx;
	int tot = 0;
	vector<int> a;
	vector<int> b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value;
		a.push_back(value);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cin >> value;
		b.push_back(value);
	}
	sort(b.rbegin(), b.rend());
	for (int i = 0; i < n; i++) {
		tot += (a[i] * b[i]);
	}
	cout << tot << endl;
}