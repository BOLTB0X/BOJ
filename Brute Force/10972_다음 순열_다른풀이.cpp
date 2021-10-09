#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(void) {
	int n;
	
	cin >> n;
	vector<int> per(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> per[i];
	}
	if (next_permutation(per.begin(), per.end())) {
		for (int i = 0; i < n; ++i) {
			cout << per[i] << ' ';
		}
	}
	else {
		cout << "-1\n";
	}
	return;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}