#include<iostream>
#include<cstring>

using namespace std;

int board[100][100];
bool visited[100][100];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 녹을 치즈가 있는지 체크
bool is_not_cheese(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1)
				return 0;
		}
	}
	return 1;
}

void DFS(int n, int m, int y, int x) {
	if (board[y][x] == 0) {
		visited[y][x] = 1;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			// 범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 재방문
			if (visited[ny][nx])
				continue;

			// 치즈 발견
			if (board[ny][nx] == 1)
				board[ny][nx] = 2; // 체크

			if (board[ny][nx] == 0)
				DFS(n, m, ny, nx);
		}
	}
	return;
}

pair<int,int> solution(int n, int m) {
	pair<int, int> answer = { 0 ,0 };
	int cheese = 0;

	while (!is_not_cheese(n, m)) {
		answer.first++;
		cheese = 0;
		memset(visited, 0, sizeof(visited));

		DFS(n, m, 0, 0);

		// 치즈 갯수 체크
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				// 녹을 치즈 발견
				if (board[i][j] == 2) {
					cheese++;
					board[i][j] = 0; // 공기 처리
				}
			}
		}
		// 바로 전 치즈 
		answer.second = cheese;
	}

	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	pair<int, int> ret = solution(n, m);
	cout << ret.first << '\n' << ret.second;
	return 0;
}