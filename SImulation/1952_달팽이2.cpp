#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;

const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

int solution(int m, int n) {
	board.resize(m, vector<int>(n, 0));

	int y = 0, x = 0, dir = 0;
	int cnt = 0;
	while (1) {
		if (board[y][x] == 1)
			break;

		board[y][x] = 1;
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n || board[ny][nx] == 1) {
			dir = (dir + 1) % 4;
			ny = y + dy[dir];
			nx = x + dx[dir];
			cnt++;
		}

		y = ny;
		x = nx;
	}
	return cnt - 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	int ret = solution(m, n);
	cout << ret;
	return 0;
}