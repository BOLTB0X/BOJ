#include <iostream>
#include <vector>

using namespace std;

int depth = 0;
vector<int> adj[101];

void DFS(int n, vector<int>& visited, int cur) {
	visited[cur] = 1;

	for (int& next : adj[cur]) {
		if (visited[next] == 1)
			continue;
		depth++;
		DFS(n, visited, next);
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;
	vector<int> visited(n + 1, 0); // 방문리스트

	DFS(n, visited, 1);
	answer = depth;
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