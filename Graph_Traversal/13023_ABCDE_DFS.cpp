#include <iostream>
#include <vector>

using namespace std;

int flag = 0;
vector<int> adj[2001];
vector<int> visited(2001, 0); // 방문리스트 초기화

void DFS(int n, int m, int cur, int level) {
	if (level == 4) {
		flag = 1;
		return;
	}

	for (int& next : adj[cur]) {
		if (visited[next] == 1)
			continue;
		visited[next] = 1;
		DFS(n, m, next, level + 1);
		visited[next] = 0;
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;

	// 각 노드에서 시작하여 길이가 m인걸 찾아야함
	for (int i = 1; i <= n; ++i) {
		visited[i] = 1;
		DFS(n, m, i, 0);

		// 있다면
		if (flag == 1)
			break;
		visited[i] = 0;

	}
	if (flag == 1)
		answer = 1;
	return answer;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
