#include <iostream>
#include <cstring>

using namespace std;

int board[51][51];
bool visited[51][51];
// »óÇÏÁÂ¿ì
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// ±íÀÌ¿ì¼±Å½»ö
void DFS(int n, int m, int y, int x) {
	visited[y][x] = 1;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		if (board[ny][nx] == 0)
			continue;

		DFS(n, m, ny, nx);
	}
	return;
}

int solution(int m, int n, int k) {
	int answer = 0;

	// ¿ÏÀüÅ½»ö
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1 && visited[i][j] == 0) {
				answer++;
				DFS(n, m, i, j);
			}
		}
	}

	return answer;
}

int main(void) {
	int T;
	int m, n, k;

	cin >> T;
	while (T--) {
		cin >> m >> n >> k;
		// ÃÊ±âÈ­
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			board[b][a] = 1;
		}

		int ret = solution(m, n, k);
		cout << ret << '\n';
	}

	return 0;
}