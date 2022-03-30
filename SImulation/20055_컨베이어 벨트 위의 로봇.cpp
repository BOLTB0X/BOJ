#include <iostream>

using namespace std;

typedef struct {
	int d;
	int robot;
} Block;

Block belts[201];

// ���ߴ� ��?
int is_break(int n, int k) {
	int cnt = 0;

	// ������ ����
	for (int i = 1; i <= 2 * n; ++i) {
		if (belts[i].d == 0)
			cnt++;
	}

	return cnt >= k ? 1 : 0;
}

// ȸ��
void belts_Rotate(int n, int k) {
	Block tmp = belts[2 * n];

	for (int i = (2 * n) - 1; i >= 1; --i)
		belts[i + 1] = belts[i];

	belts[1] = tmp;

	// ������ ĭ�� �κ��� �ִٸ�
	if (belts[n].robot == 1)
		belts[n].robot = 0;
	return;
}

// �κ� �̵�
void robot_Move(int n, int k) {
	for (int i = n - 1; i >= 1; --i) {
		// ���� ĭ�� �κ��� �ְ�
		if (belts[i].robot == 1) {
			// ���� ĭ�� �κ��� ���� �������� 1 �̻��̸�
			if (belts[i + 1].robot == 0 && belts[i + 1].d >= 1) {
				belts[i].robot = 0;
				belts[i + 1].robot = 1;
				belts[i + 1].d--;
			}
		}
	}
	// ������ ĭ�� �κ��� �ִٸ�
	if (belts[n].robot == 1)
		belts[n].robot = 0;

	// �κ� �ø���
	if (belts[1].d >= 1 && belts[1].robot == 0) {
		belts[1].d--;
		belts[1].robot = 1;
	}

	return;

}

int solution(int n, int k) {
	int answer = 0;

	while (1) {
		if (is_break(n, k) == 1)
			break;

		belts_Rotate(n, k);
		robot_Move(n, k);
		answer++;
	}

	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> belts[i].d;
		belts[i].robot = 0;
	}

	int ret = solution(n, k);
	cout << ret;
	return 0;
}