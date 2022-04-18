#include <iostream>
#include <vector>

using namespace std;

int board[21][21];
int dice[7]; // 주사위

// 동 서 남 북
const int dx[5] = { 0,0,0,-1,1 };
const int dy[5] = { 0,1,-1,0,0 };

bool is_rolling(int n, int m, int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dice_rolling(int dir) {
	int tmp = dice[1];
	
	// 동
	if (dir == 1) {
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
	}

	// 서
	else if (dir == 2) {
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = tmp;
	}

	// 남
	else if (dir == 3) {
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = tmp;
	}

	// 북
	else if (dir == 4) {
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;
	}

	return;
}

vector<int> solution(int n, int m, int x, int y, int k, vector<int>& cmd) {
	vector<int> answer;
	int cx = x, cy = y;

	for (int& c : cmd) {
		int nx = cx + dx[c];
		int ny = cy + dy[c];

		// 굴릴수 없다면
		if (!is_rolling(n, m, nx, ny))
			continue;

		dice_rolling(c); // 주사위 굴림

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

		// 윗면
		answer.push_back(dice[1]);
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
