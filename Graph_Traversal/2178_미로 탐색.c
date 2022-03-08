#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 10001 //최대 길이

typedef struct {
	int y, x, dist;
} Block;

Block que[MS];
int fr = 0, re = 0;

void enqueue(Block data) {
	que[re++] = data;
	return;
}

Block dequeue(void) {
	return que[fr++];
}

int board[101][101];
int visited[101][101];

//상하우좌
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//너비우선 탐색
int BFS(int n, int m) {
	//큐가 비어질때까지
	while (fr < re) {
		Block cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			//벽인 경우
			if (board[ny][nx] == 0)
				continue;
			
			//현재 이동 거리
			int nd = cur.dist + 1;
			//재방문인 경우
			if (visited[ny][nx] <= nd)
				continue;

			visited[ny][nx] = nd;
			Block next = { ny, nx, nd };
			enqueue(next);
		}
	}

	return visited[n - 1][m - 1];
}

int solution(int n, int m) {
	int answer = 0;

	visited[0][0] = 1;
	Block start = { 0,0,1 };
	enqueue(start);

	answer = BFS(n, m);
	return answer;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &board[i][j]);
			visited[i][j] = MS;
			//어차피 못지나가므로
			if (board[i][j] == 0)
				visited[i][j] = 0;
		}
	}

	int ret = solution(n, m);
	printf("%d", ret);
	return 0;
}