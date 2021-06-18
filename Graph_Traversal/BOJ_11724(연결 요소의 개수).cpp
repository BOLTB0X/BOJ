#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
queue<int> que;
bool visited[10001];
int n, m;

int bfs(int start) {
	que.push(start);
	visited[start] = true;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				que.push(next);
				visited[next] = true;
			}
		}
	}
	return true;
}

int main(void) {
	int result=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <=n; i++) {
		if (!visited[i]) {
			bfs(i);
			result += 1;
		}
	}
	cout << result;
}