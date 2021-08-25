#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[101] = {0,};

	for (int i = 0; i < m; i++) {
		int j, k, l;
		cin >> j >> k >> l;
		for (int start = j; start <= k; start++) {
			arr[start] = l;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}