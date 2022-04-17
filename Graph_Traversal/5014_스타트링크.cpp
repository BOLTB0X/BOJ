#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int f, int s, int g, int u, int d) {
	int answer = -1;
	vector<bool> visited(f + 1, 0); // 방문리스트
	queue<pair<int, int>> que;
	
	que.push({ s,0 });
	visited[s] = 1;
	// BFS
	while (!que.empty()) {
		int cur = que.front().first;
		int cnt = que.front().second;
		que.pop();

		if (cur == g) {
			answer = cnt;
			break;
		}

		else {
			if (cur + u <= f && visited[cur + u] == 0) {
				visited[cur + u] = 1;
				que.push({ cur + u, cnt + 1 });
			}
			if (cur - d >= 1 && visited[cur - d] == 0) {
				visited[cur - d] = 1;
				que.push({ cur - d, cnt + 1 });
			}
		}
	}
	return answer;
}

int main(void) {
	int f, s, g, u, d;

	cin >> f >> s >> g >> u >> d;
	int ret = solution(f, s, g, u, d);
	if (ret == -1)
		cout << "use the stairs";
	else
		cout << ret;

	return 0;
}