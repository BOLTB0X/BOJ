#include <iostream>

using namespace std;

int max_cnt = 0;
char board[51][51];

//�� ���� ī��Ʈ
void count_row(int n) {
	for (int y = 1; y <= n; ++y) {
		int cnt = 1;
		for (int x = 1; x <= n; ++x) {
			if (board[x][y] == board[x + 1][y])
				cnt++;
			else {
				if (cnt > max_cnt)
					max_cnt = cnt;
				cnt = 1;
			}
		}
	}
}

//�� ���� ī��Ʈ
void count_col(int n) {
	for (int y = 1; y <= n; ++y) {
		int cnt = 1;
		for (int x = 1; x <= n; ++x) {
			if (board[y][x] == board[y][x + 1])
				cnt++;
			else {
				if (cnt > max_cnt)
					max_cnt = cnt;
				cnt = 1;
			}
		}
	}
}

void solution(void) {
	int n;
	//�Է�
	cin >> n;
	for (int y = 1; y <= n; ++y)
		for (int x = 1; x <= n; ++x)
			cin >> board[y][x];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - 1; ++j) {
			//�ϳ��� ��ü�ϸ� �ִ밪 ã��
			//���� ��ü
			swap(board[i][j], board[i][j + 1]);

			count_row(n);
			count_col(n);
			//����ġ�� ��������
			swap(board[i][j + 1], board[i][j]);

			//���� ��ü
			swap(board[j][i], board[j + 1][i]);

			count_row(n);
			count_col(n);
			//����ġ�� ��������
			swap(board[j + 1][i], board[j][i]);
		}
	}

	cout << max_cnt << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}