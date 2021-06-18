#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
queue<int> que;
int n, m, k, a, b;

void dfs(int start) {
	visited[start] = true;
	cout << start << ' ';
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next])
			dfs(next);
	}
}

void bfs(int start) {
	que.push(start);
	visited[start] = true;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		cout << cur << ' ';
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				que.push(next);
				visited[next] = true;
			}
		}
	}
}

void reset() {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}

int main(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(k);
	reset();
	printf("\n");
	bfs(k);
}