#include<iostream>
#include<vector>

using namespace std;

int result = 1e9;
int board[11][11];
vector<int> visited;

int Min(int a, int b) {
	return a < b ? a : b;
}

void DFS(int n, int start, int cur, int tot, int level) {
	if (level == n - 1) {
		if (board[cur][start] != 0)
			result = Min(result, tot + board[cur][start]);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (board[cur][i] == 0)
			continue;

		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		DFS(n, start, i, tot + board[cur][i], level + 1);
		visited[i] = 0;
	}
	return;
}

int solution(int n) {
	int answer = 0;
	visited = vector<int>(n + 1, 0); // √ ±‚»≠
	
	for (int i = 0; i < n; ++i) {
		visited[i] = 1;
		DFS(n, i, i, 0, 0);
		visited[i] = 0;
	}

	answer = result;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n);
	cout << ret;
	return 0;
}