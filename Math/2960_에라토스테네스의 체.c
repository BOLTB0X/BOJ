#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;
//�迭 �ʱ�ȭ
int arr[1001] = { 0, };

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);

	//����
	for (int i = 1; i <= n; ++i)
		arr[i] = i;

	//�����佺�׳׽��� ü ����
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		//i�� 2���� �����Ͽ� ����� ���ʷ� ����
		for (int j = i; j <= n; j += i) {
			if (arr[j] != 0) {
				arr[j] = 0;
				//� �������� üũ
				cnt++;

				//cnt ������ k�� �������� ������ k��° ������ ��
				if (cnt == k) {
					printf("%d\n",j);
					return 0;
				}
			}
		}
	}
}