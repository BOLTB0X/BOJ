#include <iostream>

using namespace std;

//백트래킹
void DFS(int* com, int n, int m, int cur, int depth) {
	if (m == depth) {
		for (int i = 0; i < m; i++) {
			cout << com[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = cur; i <= n; i++) {
		com[depth] = i;
		DFS(com, n, m, i, depth + 1);
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int com[9];

	cin >> n >> m;
	//백트래킹
	DFS(com, n, m, 1, 0);
	return 0;
}