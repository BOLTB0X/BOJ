#include <iostream>
#include <vector>
using namespace std;

int board[21][21];
int dice[7] = { 0,0,0,0,0,0,0 };
// 동 서 남 북
const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, 1, -1, 0, 0};

void Roll_dice(int dir) {
	int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4],
		d5 = dice[5], d6 = dice[6];

	// 동
	if (dir == 1) {
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
	}
	
	// 서
	else if (dir == 2) {
		dice[4] = d1;
		dice[6] = d4;
		dice[3] = d6;
		dice[1] = d3;
	}
	
	// 남
	else if (dir == 3) {
		dice[1] = d5;
		dice[2] = d1;
		dice[6] = d2;
		dice[5] = d6;
	}
	
	// 북
	else if (dir == 4) {
		dice[5] = d1;
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
	}

	return;
}

vector<int> solution(int n, int m, int x, int y, int k, vector<int>& cmd) {
	vector<int> answer;
	int cx = x;
	int cy = y;

	for (int i = 0; i < cmd.size(); ++i) {
		int nx = cx + dx[cmd[i]];
		int ny = cy + dy[cmd[i]];
		int dir = cmd[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		Roll_dice(dir);
		// 이동한 칸에 쓰여 있는 수가 0이면, 
		// 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
		if (board[nx][ny] == 0)
			board[nx][ny] = dice[6];
		
		// 0이 아닌 경우에는 칸에 쓰여 있는 수가 
		// 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
		else {
			dice[6] = board[nx][ny];
			board[nx][ny] = 0;
		}

		// 상단 
		answer.push_back(dice[1]);
		// 교체
		cx = nx, cy = ny;
	}

	return answer;
}

int main(void) {
	int n, m;
	int x, y, k;
	
	cin >> n >> m >> x >> y >> k;
	vector<int> cmd;

	// 동 1 서 2 북 3 남 4 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	for (int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		cmd.push_back(c);
	}

	vector<int> ret = solution(n, m, x, y, k, cmd);
	for (int& r : ret) 
		cout << r << '\n';
	
	return 0;
}