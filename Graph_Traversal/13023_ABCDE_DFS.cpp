#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[2001];
bool visited[2001];
bool answer;

void DFS(int start, int depth) {
	visited[start] = true;

	if (depth == 4) {
		answer = true;
		return;
	}

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next]) {
			DFS(next, depth + 1);
			visited[next] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		//무향이므로
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 0; i < n; i++) {
		DFS(i,0);
		visited[i] = false;
		if (answer) 
			break;
	}
	cout << answer << '\n';
	return 0;
}