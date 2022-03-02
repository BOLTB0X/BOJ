#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 201

typedef struct {
	int d, flag;
} Block;

Block belt[MS];

//����Ǵ� �� üũ
int check(int n, int k) {
	int cnt = 0;

	for (int i = 1; i <= 2 * n; ++i) {
		if (belt[i].d == 0)
			cnt++;
	}

	return cnt >= k ? 1 : 0;
}

//ȸ��
void belt_rotate(int n, int k) {
	Block tmp = belt[2 * n];

	// - > �������� ȸ��
	for (int i = 2 * n - 1; i >= 1; --i)
		belt[i + 1] = belt[i];
	belt[1] = tmp;

	//ȸ�� �� �κ��� ������ ��ġ�� �κ��� �ִٸ�
	if (belt[n].flag == 1)
		belt[n].flag = 0;

	return;
}

//�̵�
void move(int n, int k) {
	//�Ųٷ�
	//1���� �����ϸ� ���� ������ ��ġ�� �ָ�����
	for (int i = n - 1; i >= 1; --i) {
		//�κ��� �ִٸ�
		if (belt[i].flag == 1) {
			//���� ĭ�� �������� 1 �̻��̰� �κ��� ���ٸ�
			if (belt[i + 1].d >= 1 && belt[i + 1].flag == 0) {
				belt[i].flag = 0;
				belt[i + 1].d--;
				belt[i + 1].flag = 1;
			}
		}
	}

	//ȸ�� �� �κ��� ������ ��ġ�� �κ��� �ִٸ�
	if (belt[n].flag == 1)
		belt[n].flag = 0;

	return;
}

//ù ���� ĭ�� �κ� ����
void input_robot(int n, int k) {
	//�������� 1 �̻��̰� �κ��� ���ٸ�
	if (belt[1].d >= 1 && belt[1].flag == 0) {
		belt[1].flag = 1;
		belt[1].d--;
	}
	
	return;
}

int solution(int n, int k) {
	int answer = 0;

	//�ù� ����
	while (1) {
		if (check(n, k) == 1) //4�� ����
			break;
		answer++;
		belt_rotate(n, k); //1�� ���� ��Ʈ ȸ��
		move(n, k); // 2�� ���� �κ� �̵�
		input_robot(n, k); //3�� ���� �κ� �ø���
	}
	return answer;
}

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= 2 * n; ++i) {
		int d;
		scanf("%d", &d);
		belt[i].d = d;
		belt[i].flag = 0; // �κ��� �ִ��� üũ
	}
	
	int ret = solution(n, k);
	printf("%d", ret);

	return 0;
}