#include <iostream>
#include <vector>

using namespace std;

int result = -1;
vector<int> adj[101];

void DFS(int n, vector<int>& visited, int cur, int end, int level) {
	if (cur == end) {
		result = level;
		return;
	}

	for (int& next : adj[cur]) {
		// 재방문 방지
		if (visited[next] == 1)
			continue;

		visited[next] = 1;
		DFS(n, visited, next, end, level + 1);
	}
	return;
}

int solution(int n, int m, int start, int end) {
	int answer = 0;
	vector<int> visited(n + 1, 0); // 방문리스트

	visited[start] = 1;
	DFS(n, visited, start, end, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n, m, start, end;

	cin >> n;
	cin >> start >> end;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;

		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ret = solution(n, m, start, end);
	cout << ret;
	return 0;
}
