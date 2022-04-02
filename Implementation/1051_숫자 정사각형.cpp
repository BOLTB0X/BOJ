#include <iostream>

using namespace std;

int board[50][50];

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int m) {
	int answer = 0;
	int len = Min(n, m); // 직사각형 안에서 정사각형을 찾는 것이므로

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < n - i; ++j) {
			for (int k = 0; k < m - i; ++k) {
				if (board[j][k] == board[j][k + i] &&
					board[j + i][k] == board[j][k] &&
					board[j + i][k + i] == board[j][k])
					answer = Max(answer, (i + 1) * (i + 1));
			}
		}
	}

	return answer;
}

int main(void) {
	int n, m;
	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j) 
			board[i][j] = tmp[j];
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}