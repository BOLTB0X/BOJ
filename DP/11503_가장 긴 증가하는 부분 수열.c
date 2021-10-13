#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, result = -1;
	scanf("%d", &n);

	//�����Ҵ� �� �Է�
	int* arr = malloc(sizeof(int) * (n + 1));
	int* dp = malloc(sizeof(int) * (n + 1));
	arr[0] = dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		dp[i] = 0;
	}

	//�κ� ������ ã�ƾ���
	//�� 2�� for������ �� ������ ������ �� �����ϴ� �Ǵ�
	for (int i = 1; i <= n; ++i) {
		//������ ũ�Ⱑ �׻� >=1
		int point = 0;
		for (int j = 1; j < i; ++j) {
			//�����Ѵٸ�
			if (arr[i] > arr[j])
				//���� ����
				point = max(point, dp[j]);
		}
		//1���� ������ �ִٴ� �� �� +1
		dp[i] = point + 1;
		result = max(result, dp[i]);
	}
	printf("%d\n", result);
	
	//�޸� ����
	free(dp);
	free(arr);

	return 0;
}