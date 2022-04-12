#include <iostream>
#include <string>
#include <vector>

using namespace std;

int result = 0;
char board[21][21];
vector<int> alp_cnt(26, 0); // 알파벳 카운트

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int Max(int a, int b) {
	return a > b ? a : b;
}

// 깊이우선탐색 -> 백트래킹
void DFS(int r, int c, int y, int x, int level) {
	result = Max(result, level); // 답 교체

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;

		if (alp_cnt[board[ny][nx] - 'A'] == 1)
			continue;

		alp_cnt[board[ny][nx] - 'A'] = 1;
		DFS(r, c, ny, nx, level + 1);
		alp_cnt[board[ny][nx] - 'A'] = 0;
	}
	
	return;
}

int solution(int r, int c) {
	int answer = 0;

	alp_cnt[board[0][0] - 'A'] = 1;
	DFS(r, c, 0, 0, 1);

	answer = result;
	return answer;
}

int main(void) {
	int r, c;
	string tmp;

	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		cin >> tmp;
		for (int j = 0; j < c; ++j) 
			board[i][j] = tmp[j];
	}

	int ret = solution(r, c);
	cout << ret;
	return 0;
}