#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
vector<int> visited; // 방문리스트

// 깊이우선탐색
void DFS(int n, int cur) {
	visited[cur] = 1;

	for (int& next : adj[cur]) {
		if (visited[next] == 1)
			continue;
		DFS(n, next);
	}
	return;
}

int solution(int n, vector<int>& arr) {
	int answer = 0;

	for (int i = 0; i < n; ++i) 
		adj[i + 1].push_back(arr[i]);
	visited = vector<int>(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0) {
			answer++;
			DFS(n, i);
		}
	}

	// 초기화
	for (int i = 1; i <= n; ++i)
		adj[i].clear();

	return answer;
}

int main(void) {
	int T, n;
	vector<int> arr;

	cin >> T;
	while (T--) {
		cin >> n;
		arr = vector<int>(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		int ret = solution(n, arr);
		cout << ret << '\n';
	}
	return 0;
}