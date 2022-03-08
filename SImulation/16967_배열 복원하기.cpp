#include <iostream>
#include <vector>

using namespace std;

//���
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

	//�迭 A�� �Ʒ��� Xĭ, ���������� Yĭ �̵����� B�� ����
	//B�� 0�̸� �������� A�� ������ �ʰ��ѰŶ� Ȯ�� �ʿ� X
	//���� A�������� Ž���� �����ϸ� B�� ��ġ�� ������ �� �� �ϳ��� ��ġ�� ������ üũ
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			//A�� B�� �Ѵ� ��ģ �Ÿ�
			if (i - x >= 0 && j - y >= 0)
				answer[i][j] = B[i][j] - answer[i - x][j - y];
			//(i, j)�� �� �迭 �� �ϳ��� ���ԵǸ�, Bi,j = Ai,j �Ǵ� Ai-X,j-Y
			else 
				answer[i][j] = B[i][j];
		}
	}

	return answer;
}

int main(void) {
	//�ʱ�ȭ
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