#include <iostream>

using namespace std;

int result;

int Abs(int a) {
	return a < 0 ? -a : a;
}

// �����¿� �밢���� �ִ°�?
int is_Process(int n, int* board, int y) {
	// �ش� ��� ���� �ִ� �� Ȯ��
	for (int i = 0; i < y; ++i) {
		// ���� ��ġ�� �ִ� �� Ȯ��
		if (board[y] == board[i] || y - i == Abs(board[y] - board[i]))
			return 0;
	}

	return 1;
}

void DFS(int n, int* board, int y) {
	// n����� ���ٸ�
	if (y == n) {
		result++;
		return;
	}

	// ���忡 �� ������ ����
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
	int board[15]; //����
	
	result = 0; // �ʱ�ȭ
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