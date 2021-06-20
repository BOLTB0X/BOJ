#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> per;
	per.resize(n); 
	for (int i = 0; i < n; i++) 
		per[i] = i + 1;
	do {
		for (int i = 0; i < n; i++) cout << per[i] << ' ';
		cout << '\n';
	} while (next_permutation(per.begin(), per.end()));
}