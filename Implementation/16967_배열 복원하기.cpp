#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>>& board,int H, int W, int X, int Y) {
	vector<vector<int>> answer(H, vector<int>(W, 0));

	//�迭 A�� �Ʒ��� Xĭ, ���������� Yĭ �̵����� B�� ����
	//B�� 0�̸� �������� A�� ������ �ʰ��ѰŶ� Ȯ�� �ʿ� X
	//���� A�������� Ž���� �����ϸ� B�� ��ġ�� ������ �� �� �ϳ��� ��ġ�� ������ üũ
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			// ��� ����
			if (i - X >= 0 && j - Y >= 0)
				answer[i][j] = board[i][j] - answer[i - X][j - Y];

			else
				answer[i][j] = board[i][j];
		}
	}

	return answer;
}

int main(void) {
	int H, W, X, Y;
	vector<vector<int>> board;
	cin >> H >> W >> X >> Y;
	board.resize(H + X, vector<int>(W + Y, 0));

	for (int i = 0; i < H + X; ++i) {
		for (int j = 0; j < W + Y; ++j)
			cin >> board[i][j];
	}

	vector<vector<int>> ret = solution(board, H, W, X, Y);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j)
			cout << ret[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}