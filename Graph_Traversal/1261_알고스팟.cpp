#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };

int solution(int n, int m, vector<vector<int>>& board) {
	int answer = 0;
	vector<vector<int>> dist(n, vector<int>(m, INF));
	queue<pair<int, int>> que;

	que.push({0,0});
	dist[0][0] = 0;

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 벽인 경우
			if (board[ny][nx] == 1) {
				if (dist[ny][nx] > dist[cy][cx] + 1) {
					dist[ny][nx] = dist[cy][cx] + 1;
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

	answer = dist[n - 1][m - 1];
	return answer;
}

int main(void) {
	int m, n;
	string tmp;
	vector<vector<int>> board;

	cin >> m >> n;
	board.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j)
			board[i][j] = tmp[j] - '0';
	}

	int ret = solution(n, m, board);
	cout << ret;
	return 0;
}
