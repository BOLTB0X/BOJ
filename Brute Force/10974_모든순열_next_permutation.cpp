#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> per;

void print_vector() {
	for (int i = 0; i < n; ++i) {
		cout << per[i] << ' ';
	}
	cout << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) 
		per.push_back(i);
	//다음순열알고리즘 이용
	do {
		print_vector();
	} while (next_permutation(per.begin(), per.end()));

	return 0;
}