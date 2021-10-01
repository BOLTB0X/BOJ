#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k;
vector<int> graph[10001];
bool visited[10001] = { false, };

//���� �켱
void DFS(int start) {
	visited[start] = true;
	cout << start << ' ';
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next])
			DFS(next);
	}
	return;
}

//�ʺ� �켱
void BFS(int start) {
	queue<int> q;
	
	q.push(start);
	visited[start] = true;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	//����
	for (int i = 1; i <= n; i++) 
		sort(graph[i].begin(), graph[i].end());
	
	//Ž�� ����
	memset(visited, false, sizeof(visited));
	DFS(k);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	BFS(k);

	return 0;
}