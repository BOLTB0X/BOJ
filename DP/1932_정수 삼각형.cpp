#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int n;
int graph[501][501];
int dp[501][501] = { 0, };

int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	//트리의 최상위 셋팅
	dp[1][1] = graph[1][1];
	//순회 시작
	for (int r = 2; r <= n; r++) {
		for (int c = 1; c <= r; c++) 
			dp[r][c] = Max(dp[r - 1][c - 1], dp[r - 1][c]) + graph[r][c];
	}
	//최하위 구간 최댓값 찾기
	int max_value = dp[n][1];
	for (int i = 2; i <= n; i++) {
		if (max_value < dp[n][i])
			max_value = dp[n][i];
	}

	return max_value;
}

int main(void) {
	scanf("%d", &n);
	
	//그래프 생성
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= r; c++) {
			scanf("%d", &graph[r][c]);
		}
	}
	int ret=solution(n);

	printf("%d", ret);
	return 0;
}
