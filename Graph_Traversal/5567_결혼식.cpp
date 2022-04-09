#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];
vector<int> visited;

// 너비우선탐색
int BFS(int n, queue<int>& que) {
	int cnt = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int& next : adj[cur]) {
			if (visited[next] == 1)
				continue;

			visited[next] = 1;
			cnt++;
		}
	}

	return cnt;
}

int solution(int n, int m) {
	int answer = 0;
	queue<int> que;
	visited.resize(n + 1, 0); // 초기화

	// 먼저 상근이 친구들
	visited[1] = 1;
	for (int& next : adj[1]) {
		visited[next] = 1;
		que.push(next);
		answer++;
	}

	// 친구들의 친구
	answer += BFS(n, que);

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