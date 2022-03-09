#include <iostream>

using namespace std;

int board[101][101];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0, 0,-1,1 };

int count_Area(int n, int m, int y, int x) {
	int cnt = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//범위초과
		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			if (board[ny][nx] < board[y][x]) 
				cnt += (board[y][x] - board[ny][nx]);
		}

		else 
			cnt += board[y][x];
	}

	return cnt;
}

int solution(int n, int m) {
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			answer += count_Area(n, m, i, j);
	}
	answer += (n * m * 2);
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m);
	cout << ret;

	return 0;
}