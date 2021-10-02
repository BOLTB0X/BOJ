#include <iostream>

using namespace std;

void DFS(int* per, int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << per[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		per[depth] = i;
		DFS(per, n, m, depth + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int per[8];

	cin >> n >> m;
	DFS(per, n, m, 0);
	return 0;
}