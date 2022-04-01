#include <iostream>
#include <vector>

using namespace std;

int board[21][21];
int result = 0x7fffffff;

// 절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

void DFS(int n, vector<int>& visited, int cur, int level) {
	// 탈출 조건
	if (level == n / 2) {
		int s_tot = 0;
		int l_tot = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				// 방문한 팀들이 스타트 팀
				if (visited[i] == 1 && visited[j] == 1)
					s_tot += board[i][j];
				// 미방문한 팀들이 링크팀
				else if (visited[i] == 0 && visited[j] == 0)
					l_tot += board[i][j];
			}
		}

		result = Min(result, Abs(s_tot - l_tot));
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		DFS(n, visited, i + 1, level + 1);
		visited[i] = 0;
	}
	return;
}

int solution(int n) {
	int answer = 0;
	vector<int> visited(n, 0); // 방문리스트
							   
	// 먼저 조합을 구함
	DFS(n, visited, 0, 0);
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
