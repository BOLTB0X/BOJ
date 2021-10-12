#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//�ּ�
int min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int n;
	scanf("%d", &n);

	//�����Ҵ� �� �ʱ�ȭ
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		dp[i] = 0;
	}
	
	//���Ͼ�
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		//2�� 3 ���ÿ� ������ �������� ��쵵 ����
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	printf("%d\n", dp[n]);
	free(dp);
	return 0;
}