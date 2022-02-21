#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ML 100001

int arr[ML];
int dp[ML];

//ū �� ��ȯ
int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int result;
	for (int i = 0; i < n; ++i) 
		dp[i] = 0;
	
	dp[0] = result = arr[0];

	//���Ҿ�
	for (int i = 1; i < n; ++i) {
		dp[i] = MAX(dp[i - 1] + arr[i], arr[i]); //������ ���ϴ��� �ᱣ���� ũ�ٸ�
		result = MAX(result, dp[i]);
	}

	return result;
}

int main(void) {
	int n, ret;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	ret = solution(n);
	printf("%d", ret);
	return 0;
}