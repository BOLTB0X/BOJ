#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int z, y, x;
} Pos;

int board[100][100][100];

int BFS(int m, int n, int h, queue<Pos>& que) {
	int day = -1; // 한 번 더 돌기 때문
	const int dy[6] = { 1, -1, 0, 0, 0, 0 };
	const int dx[6] = { 0, 0, -1, 1, 0, 0 };
	const int dz[6] = { 0, 0, 0, 0, 1, -1 };

	while (!que.empty()) {
		int q_size = que.size();

		while (q_size--) {
			int cz = que.front().z;
			int cy = que.front().y;
			int cx = que.front().x;
			que.pop();

			for (int dir = 0; dir < 6; ++dir) {
				int nz = cz + dz[dir];
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h)
					continue;

				// 안익은 토마토가 아니면
				if (board[nz][ny][nx] == 0) {
					board[nz][ny][nx] = 1;
					que.push({ nz,ny,nx });
				}
			}
		}
		day++;
	}

	return day;
}

int solution(int m, int n, int h) {
	int answer = 0;
	int flag = 0;
	queue<Pos> que;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				// 토마토 발견
				if (board[i][j][k] == 1) 
					que.push({ i,j,k });
			}
		}
	}

	answer = BFS(m, n, h, que);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				// 안익은 토마토 발견
				if (board[i][j][k] == 0) {
					answer = -1;
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
	return answer;
}

int main(void) {
	int m, n, h;

	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k)
				cin >> board[i][j][k];
		}
	}

	int ret = solution(m, n, h);
	cout << ret;
	return 0;
}
