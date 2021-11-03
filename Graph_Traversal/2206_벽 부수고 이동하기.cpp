#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>

using namespace std;

//좌표,부순지체크, 이동횟수
struct NODE{
	int y, x;
	int crush_cnt;
	int move_cnt;
};

int n, m;
int board[1001][1001];
//방문 및 벽을 부순 경우
bool visited[1001][1001][2]; 
queue<NODE> q;

//너비우선
int BFS(void) {
	//상하좌우
	const int dy[4] = { 1,-1,0,0 };
	const int dx[4] = { 0,0,-1,1 };

	q.push({ 0,0,0,1 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		NODE cur = q.front();
		q.pop();
		//탈출 조건
		if (cur.y == n - 1 && cur.x == m - 1) 
			return cur.move_cnt;
		
		//상하좌우 탐색
		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위 안에 들어옴
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if (board[ny][nx] == 1 && cur.crush_cnt == 0) {
					visited[ny][nx][cur.crush_cnt + 1] = true;
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

void solution(void) {
	//입력
	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) 
			board[i][j] = tmp[j] - '0';
	}
	
	//BFS로 정답 반환
	int ret = BFS();

	cout << ret << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
