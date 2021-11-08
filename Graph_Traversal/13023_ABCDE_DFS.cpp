#include <iostream>
#include <vector>

using namespace std;

bool flag;

//깊이우선탐색
void DFS(vector<vector<int>>& adj, vector<bool>& visited, int start, int depth) {
	visited[start] = true;

	//깊이가 4까지 간다면
	if (depth == 4) {
		flag = true;
		return;
	}

	//현재 노드에 연결되어 있는 노드 탐색
	for (int i = 0; i < adj[start].size(); ++i) {
		//다음 노드
		int next = adj[start][i];
		
		//재방문인 경우
		if (visited[next])
			continue;

		//다음 노드 깊이우선탐색
		DFS(adj, visited, next, depth + 1);
		visited[next] = false;
	}

	return;
}

void solution(void) {
	int n, m;

	cin >> n >> m;

	//인접그래프,방문리스트 생성 및 초기화
	vector<vector<int>> adj_graph(n + 1);
	vector<bool> visited(n + 1, false);

	//입력
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		//무향이므로
		adj_graph[a].push_back(b);
		adj_graph[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		DFS(adj_graph, visited, i, 0);
		//호출 후 해당 노드 미방문 처리
		visited[i] = false;
		
		//만약 answer가 true이면
		if (flag)
			break;
	}

	if (flag)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
