#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
vector<int> visited(1001, 0);

void DFS(int n, int m, int cur) {
	visited[cur] = 1;

	for (int& next : adj[cur]) {
		if (visited[next] == 1)
			continue;

		DFS(n, m, next);
	}

	return;
}

int solution(int n, int m) {
	int answer = 0;

	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0) {
			answer++;
			DFS(n, m, i);
		}
	}

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