#include <iostream>
#include <vector>

using namespace std;

//출력
void print_Arr(vector<vector<int>>& A, int row, int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
	return;
}

vector<vector<int>> solution(int h, int w, int x, int y, vector<vector<int>>& B) {
	vector<vector<int>> answer(h, vector<int> (w, 0)); // A

	//배열 A를 아래로 X칸, 오른쪽으로 Y칸 이동시켜 B를 만듬
	//B가 0이면 겹쳐져도 A의 범위를 초과한거라 확인 필요 X
	//원래 A기준으로 탐색을 진행하며 B와 겹치는 구간과 둘 중 하나만 겹치는 구간만 체크
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			//A와 B가 둘다 겹친 거면
			if (i - x >= 0 && j - y >= 0)
				answer[i][j] = B[i][j] - answer[i - x][j - y];
			//(i, j)가 두 배열 중 하나에 포함되면, Bi,j = Ai,j 또는 Ai-X,j-Y
			else 
				answer[i][j] = B[i][j];
		}
	}

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int H, W, X, Y;
	vector<vector<int>> B;
	cin >> H >> W >> X >> Y;

	B.resize(H + X, vector<int>(W + Y, 0));
	for (int i = 0; i < H + X; ++i) {
		for (int j = 0; j < W + Y; ++j)
			cin >> B[i][j];
	}

	vector<vector<int>> ret = solution(H, W, X, Y, B);

	print_Arr(ret, H, W);
	return 0;
}