#include <iostream>
#include <vector>
using namespace std;

int board[21][21];
int dice[7] = { 0,0,0,0,0,0,0 };
// �� �� �� ��
const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, 1, -1, 0, 0};

void Roll_dice(int dir) {
	int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4],
		d5 = dice[5], d6 = dice[6];

	// ��
	if (dir == 1) {
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
	}
	
	// ��
	else if (dir == 2) {
		dice[4] = d1;
		dice[6] = d4;
		dice[3] = d6;
		dice[1] = d3;
	}
	
	// ��
	else if (dir == 3) {
		dice[1] = d5;
		dice[2] = d1;
		dice[6] = d2;
		dice[5] = d6;
	}
	
	// ��
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
		// �̵��� ĭ�� ���� �ִ� ���� 0�̸�, 
		// �ֻ����� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����ȴ�.
		if (board[nx][ny] == 0)
			board[nx][ny] = dice[6];
		
		// 0�� �ƴ� ��쿡�� ĭ�� ���� �ִ� ���� 
		// �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� ���� �ִ� ���� 0�� �ȴ�.
		else {
			dice[6] = board[nx][ny];
			board[nx][ny] = 0;
		}

		// ��� 
		answer.push_back(dice[1]);
		// ��ü
		cx = nx, cy = ny;
	}

	return answer;
}

int main(void) {
	int n, m;
	int x, y, k;
	
	cin >> n >> m >> x >> y >> k;
	vector<int> cmd;

	// �� 1 �� 2 �� 3 �� 4 
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