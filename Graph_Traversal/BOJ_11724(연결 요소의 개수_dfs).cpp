#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10001];
bool visited[10001];
int n, m;

void dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next])
			dfs(next);
	}
	return;
}

int main(void) {
	int result = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			result += 1;
			dfs(i);
		}
	}
	cout << result;
}