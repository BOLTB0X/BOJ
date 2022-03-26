#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>>& board,int H, int W, int X, int Y) {
	vector<vector<int>> answer(H, vector<int>(W, 0));

	//배열 A를 아래로 X칸, 오른쪽으로 Y칸 이동시켜 B를 만듬
	//B가 0이면 겹쳐져도 A의 범위를 초과한거라 확인 필요 X
	//원래 A기준으로 탐색을 진행하며 B와 겹치는 구간과 둘 중 하나만 겹치는 구간만 체크
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			// 모두 포함
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