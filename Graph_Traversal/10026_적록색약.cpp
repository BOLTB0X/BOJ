#include <iostream>
#include <string>
#include <vector>

using namespace std;

char board[100][100];
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 깊이우선탐색
void DFS(int n, vector<vector<int>>& visited, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		if (board[ny][nx] != board[y][x])
			continue;

		visited[ny][nx] = 1;
		DFS(n, visited, ny, nx);
	}
	return;
}

pair<int, int> solution(int n) {
	pair<int, int> answer = { 0,0 };
	vector<vector<int>> visited(n, vector<int>(n, 0)); // 방문리스트

	// 일반용
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] == 0) {
				answer.first++;
				visited[i][j] = 1;
				DFS(n, visited, i, j);
			}
		}
	}

	// 색맹용
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'R')
				board[i][j] = 'G';
		}
	}

	visited = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] == 0) {
				answer.second++;
				visited[i][j] = 1;
				DFS(n, visited, i, j);
			}
		}
	}
	return answer;
}

int main(void) {
	int n;
	string tmp;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < n; ++j)
			board[i][j] = tmp[j];
	}

	pair<int, int> ret = solution(n);
	cout << ret.first << ' ' << ret.second;
	return 0;
}