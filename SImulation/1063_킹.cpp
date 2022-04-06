#include <iostream>
#include <string>
#include <vector>

using namespace std;

int board[8][8];
// R, L, B, T, RT, LT, RB, LB
const int dy[8] = { 0, 0, 1, -1, -1,-1,1,1 };
const int dx[8] = { 1, -1, 0, 0,1,-1,1,-1 };

int turn_dir(string c) {
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

	int ky = '8' - sk[1];
	int kx = sk[0] - 'A';

	int sy = '8' - sst[1];
	int sx = sst[0] - 'A';

	// 왕이 먼저 움직임
	for (string& c : cmd) {
		int dir = turn_dir(c);

		int nky = ky + dy[dir];
		int nkx = kx + dx[dir];
		
		if (nky < 0 || nkx < 0 || nky >= 8 || nkx >= 8)
			continue;
		
		if (nky == sy && nkx == sx) {
			int nsy = sy + dy[dir];
			int nsx = sx + dx[dir];

			if (nsy < 0 || nsx < 0 || nsy >= 8 || nsx >= 8)
				continue;

			sy = nsy, sx = nsx;
		}
		ky = nky, kx = nkx;
	}

	string ans1,ans2;
	ans1.push_back((char)kx + 'A');
	ans1.push_back(8 - ky + '0');
	ans2.push_back((char)sx + 'A');
	ans2.push_back((8 - sy + '0'));

	answer[0] = ans1;
	answer[1] = ans2;
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
