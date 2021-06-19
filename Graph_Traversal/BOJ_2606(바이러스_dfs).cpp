#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int n, m, k, a, b;
int cnt = 0;

int dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next]) {
			dfs(next);
			cnt += 1;
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
	cout << dfs(1);
}