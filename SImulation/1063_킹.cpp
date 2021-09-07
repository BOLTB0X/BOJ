#include <iostream>
#include <string>
#include <vector>
using namespace std;

string king, stone;
int n;
vector<string> move_plan;
//R,L,B,T,RT,LT,RB,LB
const int dr[8] = { 0,0,1,-1,-1,-1,1,1 };
const int dc[8] = { 1,-1,0,0,1,-1,1,-1 };

bool is_range(int row, int col) {
	if (row < 0 || col < 0 || row >= 8 || col >= 8) {
		return false;
	}
	return true;
}

int turn_dir(string s) {
	if (s == "R")
		return 0;
	else if (s == "L")
		return 1;
	else if (s == "B")
		return 2;
	else if (s == "T")
		return 3;
	else if (s == "RT")
		return 4;
	else if (s == "LT")
		return 5;
	else if (s == "RB")
		return 6;
	else if (s == "LB")
		return 7;
}

void simulation(int kc, int sc, int kr, int sr) {
	for (int i = 0; i < move_plan.size(); i++) {
		int dir = turn_dir(move_plan[i]);
		
		int nkc = kc + dc[dir];
		int nkr = kr + dr[dir];
		//범위 밖이면
		if (!is_range(nkr, nkc))
			continue;
		//이동 위치가 돌의 위치면
		if (nkc == sc && nkr == sr) {
			int nsc = sc + dc[dir];
			int nsr = sr + dr[dir];
			//범위 밖이면
			if (!is_range(nsr, nsc))
				continue;
			sc = nsc;
			sr = nsr;
		}
		kc = nkc;
		kr = nkr;
	}
	cout << (char)(kc+'A') << 8-kr << '\n';
	cout << (char)(sc+'A') << 8-sr << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int kc, sc, kr, sr;
	cin >> king >> stone >> n;

	kc = king[0] - 'A';
	sc = stone[0] - 'A';
	kr = ('8' - king[1]);
	sr = ('8' - stone[1]);
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		move_plan.push_back(cmd);
	}
	simulation(kc, sc, kr, sr);
	return 0;
}