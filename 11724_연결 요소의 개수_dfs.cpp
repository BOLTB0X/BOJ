#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[1001];
bool visited[1001];

void DFS(int start) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next])
			DFS(next);
	}
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int result = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			result++;
			DFS(i);
		}
	}
	cout << result << '\n';
	return 0;
}