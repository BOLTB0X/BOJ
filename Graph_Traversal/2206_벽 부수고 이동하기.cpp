#include <cstdio>
#include <queue>
using namespace std;

struct NODE{
	int y, x;
	int crush_cnt;
	int move_cnt;
};

int n, m;
int board[1001][1001];
//방문 및 벽을 부순 경우
bool visited[1001][1001][2]; 

//상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//입력
void input(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
}

//범위체크
bool is_range(int row, int col) {
	if (row <1 || col < 1 || row >n || col > m)
		return false;
	else
		return true;
}

//너비우선
int BFS(queue<NODE> &q) {
	q.push({ 1,1,0,1 });
	visited[1][1][0] = true;
	
	while (!q.empty()) {
		NODE cur = q.front();
		q.pop();
		//탈출 조건
		if (cur.y == n && cur.x == m) {
			return cur.move_cnt;
		}
		//상하좌우 탐색
		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (is_range(ny, nx)) {
				if (board[ny][nx] == 1 && cur.crush_cnt == 0) {
					visited[ny][nx][cur.crush_cnt] = true;
					q.push({ ny,nx,cur.crush_cnt + 1,cur.move_cnt + 1 });
				}
				if (board[ny][nx] == 0 && !visited[ny][nx][cur.crush_cnt]) {
					visited[ny][nx][cur.crush_cnt] = true;
					q.push({ ny,nx,cur.crush_cnt,cur.move_cnt + 1 });
				}
			}
		}
	}
	return -1;

}

int main(void) {
	//입력
	input();
	queue<NODE> q;
	//BFS로 정답 반환
	int ret = BFS(q);
	//정답 출력
	printf("%d", ret);
	return 0;
}
