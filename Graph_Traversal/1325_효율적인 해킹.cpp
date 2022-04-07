#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
int max_cnt = 0;
vector<int> adj[10001];
vector<int> visited;

void DFS(int n, int cur) {
	visited[cur] = 1;
	cnt++;

	for (int& next : adj[cur]) {
		if (visited[next] == 1)
			continue;

		DFS(n, next);
	}
	return;
}

vector<int> solution(int n, int m) {
	vector<int> answer;

	for (int i = 1; i <= n; ++i) {
		visited = vector<int>(n + 1, 0); // 매 방문리스트 초기화
		cnt = 0;

		DFS(n, i);

		if (cnt > max_cnt) {
			answer.clear(); // 초기화
			answer.push_back(i);
			max_cnt = cnt;
		}

		else if (cnt == max_cnt)
			answer.push_back(i);
	}
	// 오름차순정렬
	sort(answer.begin(), answer.end());
	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;

		cin >> a >> b;
		// A -> B를 신뢰
		// B를 해킹하면 A 해킹가능
		adj[b].push_back(a);
	}

	vector<int> ret = solution(n, m);
	for (int& r : ret)
		cout << r << ' ';
	return 0;
}