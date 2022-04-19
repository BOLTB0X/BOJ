#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

int N, M;
int board[100][100];

// 상 우 하 좌
const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };

int solution(void) {
	int answer = 0;
	vector<vector<int>> dist(N, vector<int>(M, INF));
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

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			// 벽인 경우
			if (board[ny][nx] == 1) {
				if (dist[ny][nx] > dist[cy][cx] + 1) {
					dist[ny][nx] = dist[cy][cx] + 1;
					que.push({ ny, nx });
				}
			}

			// 뚫인 경우
			else if (board[ny][nx] == 0) {
				if (dist[ny][nx] > dist[cy][cx]) {
					dist[ny][nx] = dist[cy][cx];
					que.push({ ny, nx });
				}
			}
		}
	}

	answer = dist[N - 1][M - 1];
	return answer;
}

int main(void) {
	string tmp;

	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		for (int j = 0; j < M; ++j)
			board[i][j] = tmp[j] - '0';
	}

	int ret = solution();
	cout << ret;
	return 0;
}
