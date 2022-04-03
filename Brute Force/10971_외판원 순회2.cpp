#include <iostream>
#include <vector>

using namespace std;

int result = 0x7fffffff; // 최소를 위한

// 최솟값 비교
int Min(int a, int b) {
	return a < b ? a : b;
}

// 순열
void DFS(int n, vector<vector<int>>& board, vector<int>& visited, int start, int cur, int tot, int level) {
	if (level == n - 1) {
		if (board[cur][start] != 0) 
			result = Min(result, tot + board[cur][start]);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (board[cur][i] != 0 && visited[i] == 0) {
			visited[i] = 1;
			DFS(n, board, visited, start, i ,tot + board[cur][i], level + 1);
			visited[i] = 0;
		}
	}
	return;
}

int solution(int n, vector<vector<int>>& board) {
	int answer = 0;
	vector<int> visited(n + 1, 0); // 방문리스트

	// 각 행을 순열로 뽑아 각 비용을 비교
	for (int i = 0; i < n; ++i) {
		visited[i] = 1;
		DFS(n, board, visited, i, i, 0, 0);
		visited[i] = 0;
	}

	answer = result;
	return answer;
}

int main(void) {
	int n;
	vector<vector<int>> board;

	cin >> n;
	board.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, board);
	cout << ret;
	return 0;
}
