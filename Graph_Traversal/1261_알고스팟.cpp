#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 1e9 // 최대

using namespace std;

const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };

int BFS(int n, int m, vector<vector<int>>& board) {
	vector<vector<int>> dist(n, vector<int>(m, INF)); // 거리
	queue<pair<int, int>> que;

	que.push({ 0,0 });
	dist[0][0] = 0;

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 범위 초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (board[ny][nx] == 1) {
				if (dist[ny][nx] > dist[cy][cx] + 1) {
					dist[ny][nx] = dist[cy][cx] + 1; // 벽을 부신 효과
					que.push({ ny,nx });
				}
			}
			
			else if (board[ny][nx] == 0) {
				if (dist[ny][nx] > dist[cy][cx]) {
					dist[ny][nx] = dist[cy][cx];
					que.push({ ny,nx });
				}
			}
		}
	}

	return dist[n - 1][m - 1];
}

int solution(int n, int m, vector<vector<int>> board) {
	int answer = 0;

	// 0 0과 n - 1, m - 1은  항상 뚫여있음
	answer = BFS(n, m, board);
	return answer;
}

int main(void) {
	int n, m;
	vector<vector<int>> board;
	string tmp;

	cin >> n >> m;
	board.resize(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		for (int j = 0; j < n; ++j)
			board[i][j] = tmp[j] - '0';
	}

	int ret = solution(m, n, board);
	cout << ret;
	return 0;
}