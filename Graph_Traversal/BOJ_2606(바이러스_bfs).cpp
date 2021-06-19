#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
queue<int> que;
int n, m, k, a, b;
int cnt = 0;

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
				cnt += 1;
				visited[next] = true;
			}
		}
	}
	return cnt;
}

int main(void) {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	cout << bfs(1);
}