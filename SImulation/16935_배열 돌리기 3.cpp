#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, R;
int board[100][100];
int cboard[100][100];
int cmd[1000];

void print_board(void) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

// 상하 반전
void one(void) {
	memset(cboard, 0, sizeof(cboard)); // 복사

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cboard[i][j] = board[N - 1 - i][j];
	}

	memcpy(board, cboard, sizeof(cboard)); // 복사
	return;
}

// 좌우 반전
void two(void) {
	memset(cboard, 0, sizeof(cboard)); // 복사

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cboard[i][j] = board[i][M - 1 - j];
	}

	memcpy(board, cboard, sizeof(cboard)); // 복사
	return;
}

// 오른쪽 90도 회전
void three(void) {
	memset(cboard, 0, sizeof(cboard)); // 복사
	int h = N;

	swap(N, M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cboard[i][j] = board[h - 1 - j][i];
	}

	memcpy(board, cboard, sizeof(cboard)); // 복사
	return;
}

// 왼쪽 90도 회전
void four(void) {
	memset(cboard, 0, sizeof(cboard)); // 복사
	int w = M;

	swap(N, M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cboard[i][j] = board[j][w - 1 - i];
	}

	memcpy(board, cboard, sizeof(cboard)); // 복사
	return;
}

void five(void) {
	memset(cboard, 0, sizeof(cboard)); // 초기화

	int h = N / 2;
	int w = M / 2;

	// 1 -> 2
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i][j + w] = board[i][j];
	}

	// 2 -> 3
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i + h][j + w] = board[i][j + w];
	}

	// 3 -> 4
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i + h][j] = board[i + h][j + w];
	}

	// 4 -> 1
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i][j] = board[i + h][j];
	}

	memcpy(board, cboard, sizeof(cboard)); // 복사
	return;
}

void six(void) {
	memset(cboard, 0, sizeof(cboard)); // 초기화

	int h = N / 2;
	int w = M / 2;

	// 4 -> 3
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i + h][j + w] = board[i + h][j];
	}

	// 3 -> 2
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i][j + w] = board[i + h][j + w];
	}

	// 1 -> 4
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i + h][j] = board[i][j];
	}

	// 2 -> 1
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cboard[i][j] = board[i][j + w];
	}

	memcpy(board, cboard, sizeof(cboard)); // 복사
	return;
}

void solution(void) {
	for (int i = 0; i < R; ++i) {
		int type = cmd[i];

		if (type == 1) 
			one();
		else if (type == 2) 
			two();
		else if (type == 3) 
			three();
		else if (type == 4) 
			four();
		else if (type == 5) 
			five();
		else if (type == 6) 
			six();
	}
	return;
}

int main(void) {
	cin >> N >> M >> R;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
	}

	for (int i = 0; i < R; ++i)
		cin >> cmd[i];

	solution();

	print_board(); // 출력
	return 0;
}
