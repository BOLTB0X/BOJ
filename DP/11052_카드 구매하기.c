#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[1001];
int cards[1001];

int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer;
	//dp���̺� �ʱ�ȭ
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	//ī�� ���ð��� 1���� n����
	for (int i = 1; i <= n; ++i) {
		//���ʷ� �ش� j�� i��ŭ ��Ͱ� �ٸ� �Ͱ� �����ؼ�
		//�� ���� �ִ� ����
		for (int j = 1; j <= i; ++j) {
			dp[i] = MAX(dp[i - j] + cards[j], dp[i]);
		}
	}

	answer = dp[n];
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &cards[i]);

	int ret = solution(n);

	printf("%d",ret);

	return 0;
}