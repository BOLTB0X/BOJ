#include <iostream>

using namespace std;

int heights[501];

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int H, int W) {
	int answer = 0;
	// ���ϼ� �ִ� ������ �����ؾ���
	// �ʺ� w�� 2 ~ w-1 �������� ���̴� �κ��� ������
	// 2���� Ž���ϸ鼭 L,R�� ������ ��, �츦 ���ϸ鼭 ���� ���� ������ ��

	for (int i = 2; i < W; ++i) {
		int left = 0, right = 0;

		// ���ʺ��� �ڱ� ��ġ ������
		for (int j = 1; j < i; ++j)
			left = Max(left, heights[j]);
		
		// ������ ������
		for (int j = i + 1; j <= W; ++j)
			right = Max(right, heights[j]);

		// ���� ���� ��
		// ���� ������ �� ���� ������ ���� ���� ����
		int cur_w = Min(left, right) - heights[i];

		// ����̸�
		if (cur_w >= 0)
			answer += cur_w;
	}

	// ��ȯ
	return answer;
}

int main(void) {
	int H, W;

	cin >> H >> W;
	for (int i = 1; i <= W; ++i) 
		cin >> heights[i];
	
	int ret = solution(H, W);
	cout << ret;

	return 0;
}