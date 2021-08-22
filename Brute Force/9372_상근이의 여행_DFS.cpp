#include <iostream>
#include <vector>
using namespace std;

int n, m; //정점, 노드
vector<int> graph[1001];
bool visited[1001];
int cnt = 0;

void DFS(int start) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next]) {
			DFS(next);
			cnt += 1;
		}
	}
}

void graph_reset() {
	for (int i = 0; i <= n; i++) {
		graph[i].clear();
	}
	for (int i = 0; i <= n; i++) {
		visited[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T;t++) {
		cin >> n >> m;
		//그래프 생성
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		DFS(1);
		cout << cnt << '\n';
		graph_reset();
		cnt = 0;
	}
	return 0;
}