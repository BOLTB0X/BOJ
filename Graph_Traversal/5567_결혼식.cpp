#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];
vector<int> visited;

// �ʺ�켱Ž��
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
	visited.resize(n + 1, 0); // �ʱ�ȭ

	// ���� ����� ģ����
	visited[1] = 1;
	for (int& next : adj[1]) {
		visited[next] = 1;
		que.push(next);
		answer++;
	}

	// ģ������ ģ��
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