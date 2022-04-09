#include <iostream>
#include <cstring>

using namespace std;

int result = 0;
int board[101][101];
int visited[101][101];

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 깊이우선탐색
void DFS(int n, int y, int x, int h) {
	visited[y][x] = 1;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 범위초과
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		
		// 재방문 
		if (visited[ny][nx] == 1)
			continue;

		if (board[ny][nx] <= h)
			continue;

		visited[ny][nx] = 1;
		DFS(n, ny, nx, h);
	}
	return;
}

int solution(int n) {
	int answer = 1;
	int max_h = 1;

	// 최대 높이 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] > max_h)
				max_h = board[i][j];
		}
	}
	
	for (int h = 1; h < max_h; ++h) {
		memset(visited, 0, sizeof(visited));
		result = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] > h && visited[i][j] == 0) {
					result++;
					DFS(n, i, j, h);
				}
			}
		}
		if (result > answer)
			answer = result;
	}

	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n);
	cout << ret;
	return 0;
}