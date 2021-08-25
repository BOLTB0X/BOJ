#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int m1[100][100] = { 0, };
	int m2[100][100] = { 0, };

	cin >> n >> m;
	int result[100][100];

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			cin >> m1[r][c];
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			cin >> m2[r][c];
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			result[r][c] = m1[r][c] + m2[r][c];
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			cout << result[r][c] << ' ';
		}
		cout << '\n';
	}
	return 0;
}