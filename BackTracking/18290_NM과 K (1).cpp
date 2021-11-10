#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> board;
vector<vector<bool>> visited;
int result = -0x7fffffff;

//동서남북
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

//최댓값반환
int max(int a, int b) {
	return a > b ? a : b;
}

//깊이우선탐색
void DFS(int depth, int tot) {
	//탈출조건
	if (depth == k) {
		result = max(result, tot);
		return;
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			//재방문인 경우
			if (visited[y][x])
				continue;

			//체크용
			bool flag = true;

			//동서남북 진행
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				//범위초과
				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (visited[ny][nx])
					flag = false;
			}

			//진행이 가능하다면
			if (flag) {
				visited[y][x] = true;
				DFS(depth + 1, tot + board[y][x]);
				visited[y][x] = false;
			}
		}
	}
	return;
}

void solution(void) {
	cin >> n >> m >> k;

	//맵과 방문리스트 초기화
	board.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m, false));

	//입력
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x)
			cin >> board[y][x];
	}

	//백트래킹 시작
	DFS(0, 0);

	//출력
	cout << result << '\n';
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