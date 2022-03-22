#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

int que[10001];
int fr = 0, re = 0;
vector<int> adj[1001]; //인접 리스트

void enqueue(int data) {
	que[re++] = data;
	return;
}

int dequeue(void) {
	return que[fr++];
}

// 깊이우선탐색
void DFS(vector<int>& visited, int cur) {
	visited[cur] = 1;
	cout << cur << ' '; // 출력

	for (int& next : adj[cur]) {
		if (visited[next] == 1)
			continue;

		DFS(visited, next); // 탐색
	}
	return;
}

// 너비우선탐색
void BFS(vector<int>& visited, int start) {
	visited[start] = 1;
	enqueue(start); // 삽입

	while (fr < re) {
		int cur = dequeue();
		cout << cur << ' ';

		for (int& next : adj[cur]) {
			if (visited[next] == 1)
				continue;

			visited[next] = 1;
			enqueue(next);
		}
	}
	return;
}

void solution(int n, int m, int v) {
	//정렬
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	vector<int> visited(n + 1, 0); // 방문리스트 선언

	// 먼저 DFS
	DFS(visited, v);
	cout << '\n';

	//초기화
	fill(visited.begin(), visited.end(), 0);
	BFS(visited, v);

	return;
}

int main(void) {
	int n, m, v;

	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) {
		int a, b;

		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	solution(n, m, v);

	return 0;
}
