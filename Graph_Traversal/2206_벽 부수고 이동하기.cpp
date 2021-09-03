#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int r, c;
	int crush_cnt;
	int move_cnt;
} inf;

int N, M;
int map[1001][1001];
bool visited[1001][1001][2]; //방문 및 벽을 부순 경우
queue<inf> q;
const int dr[4] = { -1,0,1,0 };
const int dc[4] = { 0,1,0,-1 };

bool is_range(int row, int col) {
	if (row <1 || col < 1 || row >N || col > M)
		return false;
	else
		return true;
 }

int BFS() {
	q.push({ 1,1,0,1 });
	visited[1][1][0] = true;
	while (!q.empty()) {
		inf cur = q.front();
		q.pop();

		if (cur.r == N && cur.c == M) {
			return cur.move_cnt;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nr = cur.r + dr[dir];
			int nc = cur.c + dc[dir];
			if (is_range(nr, nc)) {
				if (map[nr][nc] == 1 && cur.crush_cnt == 0) {
					visited[nr][nc][cur.crush_cnt] = true;
					q.push({ nr,nc,cur.crush_cnt + 1,cur.move_cnt + 1 });
				}
				if (map[nr][nc] == 0 && !visited[nr][nc][cur.crush_cnt]) {
					visited[nr][nc][cur.crush_cnt] = true;
					q.push({ nr,nc,cur.crush_cnt,cur.move_cnt + 1 });
				}
			}
		}
	}
	return -1;

}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int ret = BFS();
	printf("%d", ret);
	return 0;
}