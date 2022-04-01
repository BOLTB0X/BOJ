#include <iostream>
#include <vector>

using namespace std;

int result = 0x7fffffff; // 최소를 위한
int board[20][20];
vector<int> visited;
 
// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

// 절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

void DFS(int n, int cur, int level) {
	// 다 도달하면
	if (n == level) {
		int s_tot = 0;
		int l_tot = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				// 방문 -> 스타트
				if (visited[i] == 1 && visited[j] == 1)
					s_tot += board[i][j];
				// 미방문 -> 링크
				else if (visited[i] == 0 && visited[j] == 0)
					l_tot += board[i][j];
			}
		}

		// 최소 차이값
		result = Min(result, Abs(s_tot - l_tot));
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		DFS(n, i + 1, level + 1);
		visited[i] = 0;
	}
	return;
}

int solution(int n) {
	int answer = 0;
	visited = vector<int>(n, 0); // 방문 리스트 초기화

	// 팀 숫자가 안맞아도 되므로
	// 1부터 n- 1까지
	for (int i = 1; i < n; ++i) 
		DFS(n, 0, i);
	

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
