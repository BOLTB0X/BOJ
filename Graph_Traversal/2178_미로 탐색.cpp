#include <iostream>

using namespace std;

typedef struct {
	int y, x;
} Pair;

Pair que[10011];
int fr = 0, re = 0;

void push(Pair data) {
	que[re++] = data;
	return;
}

int board[101][101];
int dist[101][101];

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 너비우선탐색
void BFS(int n, int m) {
	push({ 0,0 });
	dist[0][0] = 1;

	// 큐가 비어질때까지
	while (fr < re) {
		int cy = que[fr].y;
		int cx = que[fr].x;
		fr++; // pop

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 벽
			if (board[ny][nx] == 0)
				continue;
			
			// 재방문
			if (dist[ny][nx] != 0)
				continue;

			dist[ny][nx] = dist[cy][cx] + 1;
			push({ ny, nx });
		}
	}

	return;
}

int solution(int n, int m) {
	int answer = 0;
	
	BFS(n, m); // 탐색
	answer = dist[n - 1][m - 1];
	return answer;
}

int main(void) {
	int n, m;
	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j) {
			board[i][j] = tmp[j] - '0';
			dist[i][j] = 0;
		}
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
