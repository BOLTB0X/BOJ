#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int y, x, dir;
} Robot;

int board[50][50];

// 0 북 1 동 2 남 3 서
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

// 왼쪽으로 회전
int turn_left(int d) {
	if (d == 0)
		return 3;
	return d - 1;
}

// 후진
int turn_back(int d) {
	if (d == 0)
		return 2;

	else if (d == 1)
		return 3;

	else if (d == 2)
		return 0;

	else if (d == 3)
		return 1;
}

int solution(int n, int m, int sy, int sx, int sd) {
	int answer = 1;
	int flag = 0;

	queue<Robot> que; // 큐
	board[sy][sx] = 2; // 청소처리
	que.push({ sy,sx,sd });

	while (!que.empty()) {
		// 탈출 조건
		if (flag == 1)
			break;

		int cy = que.front().y;
		int cx = que.front().x;
		int cd = que.front().dir;
		int tmp = cd;
		que.pop();

		// 현재 방향 기준으로 왼쪽부터 차례로
		for (int i = 0; i < 4; ++i) {
			tmp = turn_left(tmp);
			int ny = cy + dy[tmp];
			int nx = cx + dx[tmp];

			// 범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 2 - a 조건
			if (board[ny][nx] == 0) {
				board[ny][nx] = 2;
				answer++;
				que.push({ ny, nx, tmp });
				break;
			}

			// 끝까지 온 경우
			else if (i == 3) {
				// 방향 유지
				int ny = cy + dy[turn_back(cd)];
				int nx = cx + dx[turn_back(cd)];

				// 범위초과
				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;

				// 2 - d 조건
				if (board[ny][nx] == 1) {
					flag = 1;
					break;
				}
				que.push({ ny, nx, cd }); // 바라보는 방향을 유지한 채
			}
		}
	}

	return answer;
}

int main(void) {
	int n, m;
	int sy, sx, sd;
	
	cin >> n >> m;
	cin >> sy >> sx >> sd;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m, sy, sx, sd);
	cout << ret;
	return 0;
}