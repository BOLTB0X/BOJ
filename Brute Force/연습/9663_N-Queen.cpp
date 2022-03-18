#include <iostream>

using namespace std;

int result;

int Abs(int a) {
	return a < 0 ? -a : a;
}

// 상하좌우 대각선에 있는가?
int is_Process(int n, int* board, int y) {
	// 해당 행과 열에 있는 지 확인
	for (int i = 0; i < y; ++i) {
		// 같은 위치에 있는 지 확인
		if (board[y] == board[i] || y - i == Abs(board[y] - board[i]))
			return 0;
	}

	return 1;
}

void DFS(int n, int* board, int y) {
	// n행까지 갔다면
	if (y == n) {
		result++;
		return;
	}

	// 보드에 열 정보를 삽입
	for (int x = 0; x < n; ++x) {
		board[y] = x;
		if (is_Process(n, board, y) == 1)
			DFS(n, board, y + 1);
		board[y] = 0;
	}
	return;
}

int solution(int n) {
	int answer = 0;
	int board[15]; //보드
	
	result = 0; // 초기화
	DFS(n, board, 0);

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