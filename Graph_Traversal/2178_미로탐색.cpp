#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101] = { false, };

//상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//입력
void input(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; ++j) {
			board[i][j] = (tmp[j] - '0');
		}
	}
}

//너비우선탐색
void BFS(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y,x });
	
	//큐가 빌때까지
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		//상하좌우 탐색
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			//범위초과
			if (ny >= n || nx >= m || nx < 0 || ny < 0)
				continue;
			//재방문 또는 벽인 경우
			if (visited[ny][nx] || board[ny][nx] == 0)
				continue;
			//거리 체크
			board[ny][nx] = board[cy][cx] + 1;
			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

//시뮬레이션
void simulation(void) {
	//입력
	input();
	//BFS시작
	BFS(0, 0);
	//최소거리는 격자판의 가장 마지막 위치
	cout << board[n - 1][m - 1] << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//시뮬시작
	simulation();
	return 0;
}