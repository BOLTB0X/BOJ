#include <iostream>

using namespace std;

//백트래킹
void DFS(int* com, bool* visited, int n, int m, int cur, int depth) {
	//특정 깊이에 도달하면
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << com[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = cur; i <= n; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		com[depth] = i;
		DFS(com, visited, n, m, i + 1, depth + 1);
		visited[i] = false;
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int com[9];
	bool visited[9] = { false, };
	
	cin >> n >> m;
	DFS(com, visited, n, m, 1, 0);
	return 0;
}
