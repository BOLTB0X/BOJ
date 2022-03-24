#include <iostream>

using namespace std;

int cnt = 0;
int board[17][17];
// 0, 1, 2
const int dy[3] = { 0,1,1 };
const int dx[3] = { 1,1,0 };

// 문제조건상 방향에 따른 비여있어야하는 곳들 체크
int is_Process(int n, int ny, int nx, int dir) {
	// 대각선은 확인해야하는 방향이 더 있음
	if (dir == 1) {
		if (ny < 1 || nx < 1 || ny > n || nx > n)
			return 0;

		if (board[ny][nx] == 1)
			return 0;

		if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1)
			return 0;
	}

	else {
		if (ny < 1 || nx < 1 || ny > n || nx > n)
			return 0;

		if (board[ny][nx] == 1)
			return 0;
	}

	return 1;
}

void DFS(int n, int y, int x, int d) {
	// 도달한다면
	if (y == n && x == n) {
		cnt++;
		return;
	}

	// 가로
	if (d == 0) {
		for (int dir = 0; dir < 2; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if(is_Process(n, ny, nx, dir) == 1)
				DFS(n, ny, nx, dir);
		}
	}
	
	// 대각선 
	else if (d == 1) {
		for (int dir = 0; dir < 3; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (is_Process(n, ny, nx, dir) == 1)
				DFS(n, ny, nx, dir);
		}
	}
	
	// 세로 
	else if (d == 2) {
		for (int dir = 1; dir < 3; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (is_Process(n, ny, nx, dir) == 1)
				DFS(n, ny, nx, dir);
		}
	}
	return;
}

int solution(int n) {
	int answer = 0;

	DFS(n, 1, 2, 0);
	answer = cnt;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n);
	cout << ret;
	return 0;
}