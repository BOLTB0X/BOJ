#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, result;
	scanf("%d", &n);
	
	//동적할당
	int* arr = malloc(sizeof(int) * n);
	int* dp = malloc(sizeof(int) * n);
	
	//입력
	for (int i = 0; i < n; ++i) 
		scanf("%d", &arr[i]);
	
	//셋팅
	dp[0] = arr[0];
	result = dp[0];
	//보턴업 방식으로 한칸 전 dp값과 더한 값과 현재 값을 비교하며 진행
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}
	
	printf("%d\n",result);
	//메모리 해제
	free(dp);
	free(arr);
	return 0;
}
