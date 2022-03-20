#include <iostream>

using namespace std;

int result;
int board[16];

// 절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

// 진행가능한 가?
int is_Process(int n, int row) {
	// 행과 열을 비교하며 상하좌우대각선이 닿는 지 확인
	for (int col = 0; col < row; ++col) {
		// 같은 위치에 있는 지 확인
		if (board[row] == board[col] || row - col == Abs(board[row] - board[col]))
			return 0;
	}

	return 1;
}

void DFS(int n, int row) {
	// 격자판 n - 1번째 행까지 갔다면 
	if (row == n) {
		result++;
		return;
	}

	for (int col = 0; col < n; ++col) {
		board[row] = col;
		if (is_Process(n, row) == 1)
			DFS(n, row + 1); // 진행
	}

	return;
}

int solution(int n) {
	int answer = 0;

	result = 0; // 초기화
	DFS(n, 0); // 백트래킹 시작
	answer = result;

	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int ret = solution(n);
	cout << ret;

	return 0;
}
