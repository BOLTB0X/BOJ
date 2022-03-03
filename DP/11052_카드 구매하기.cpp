#include <iostream>
#define MN 1001

using namespace std;

int cards[MN];
int dp[MN];

//�ִ� ��ȯ
int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = 0;
	//dp���̺� �ʱ�ȭ
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;
	
	
	//���Ҿ�
	for (int i = 1; i <= n; ++i) {
		//i�� �ִ� ī�带 ���� ����, j�� ī�� ������ ����
		for (int j = 1; j <= i; ++j)
			dp[i] = MAX(dp[i - j] + cards[j], dp[i]);
	}

	answer = dp[n];

	return answer;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> cards[i];
	
	int ret = solution(n);
	cout << ret;

	return 0;
}