#include <iostream>
#include <string>
#include <vector>

using namespace std;

int board[8][8];

// R L B T RT LT RB LB
const int dy[8] = { 0, 0, 1, -1, -1, -1, 1, 1};
const int dx[8] = { 1, -1,0, 0, 1, -1, 1, -1 };

int trans_cmd(string c) {
	if (c == "R")
		return 0;

	else if (c == "L")
		return 1;

	else if (c == "B")
		return 2;

	else if (c == "T")
		return 3;

	else if (c == "RT")
		return 4;

	else if (c == "LT")
		return 5;
	
	else if (c == "RB")
		return 6;
	
	else if (c == "LB")
		return 7;
}

vector<string> solution(string sk, string sst, int n, vector<string>& cmd) {
	vector<string> answer(2);

	// 킹
	int sx = sk[0] - 'A';
	int sy = '8' - sk[1];
	
	// 돌
	int tx = sst[0] - 'A';
	int ty = '8' - sst[1];

	for (string& c : cmd) {
		int dir = trans_cmd(c);
		int nsy = sy + dy[dir];
		int nsx = sx + dx[dir];

		if (nsy < 0 || nsx < 0 || nsy >= 8 || nsx >= 8)
			continue;

		if (nsy == ty && nsx == tx) {
			int nty = ty + dy[dir];
			int ntx = tx + dx[dir];

			if (nty < 0 || ntx < 0 || nty >= 8 || ntx >= 8)
				continue;

			ty = nty, tx = ntx;
		}

		sy = nsy, sx = nsx;
	}
	
	answer[0] += (sx + 'A');
	answer[0] += (8 - sy + '0');
	answer[1] += (tx + 'A');
	answer[1] += (8 - ty + '0');
	return answer;
}

int main(void) {
	string sy, sx;
	int n;
	vector<string> cmd;

	cin >> sy >> sx >> n;
	cmd.resize(n);
	
	for (int i = 0; i < n; ++i)
		cin >> cmd[i];

	vector<string> ret = solution(sy, sx, n, cmd);
	cout << ret[0] << '\n' << ret[1];
	return 0;
}
