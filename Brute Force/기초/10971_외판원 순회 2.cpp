#include <iostream>

using namespace std;

int result = 1e9;
int board[11][11];
int visited[11];

int Min(int a, int b) {
	return a < b ? a : b;
}

// 초기화
void init(int n) {
	for (int i = 0; i <= n; ++i)
		visited[i] = 0;
	return;
}

int is_All_visit(int n) {
	for (int i = 1; i < n; ++i)
		if (visited[i] == 0) return 0;

	return 1;
}

void DFS(int n, int cur, int tot) {
	if (is_All_visit(n) == 1) {
		if (board[cur][0] != 0)
			result = Min(result, tot + board[cur][0]);
		return;
	}

	for (int i = 1; i < n; ++i) {
		if (visited[i] == 1)
			continue;

		if (board[cur][i] == 0)
			continue;

		visited[i] = 1;
		DFS(n, i, tot + board[cur][i]);
		visited[i] = 0;
	}

	return;
}

int solution(int n) {
	int answer = 0;

	init(n); // 방문리스트 초기화

	DFS(n, 0, 0);
	
	answer = result;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j =0; j < n; ++j)
			cin >> board[i][j];
	}
	int ret = solution(n);
	cout << ret;
	return 0;
}
