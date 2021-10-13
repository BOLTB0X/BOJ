#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, result = -1;
	scanf("%d", &n);

	//동적할당 및 입력
	int* arr = malloc(sizeof(int) * (n + 1));
	int* dp = malloc(sizeof(int) * (n + 1));
	arr[0] = dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		dp[i] = 0;
	}

	//부분 수열을 찾아야함
	//즉 2중 for문으로 한 지점을 지정한 뒤 증가하는 판단
	for (int i = 1; i <= n; ++i) {
		//수열의 크기가 항상 >=1
		int point = 0;
		for (int j = 1; j < i; ++j) {
			//증가한다면
			if (arr[i] > arr[j])
				//지점 변경
				point = max(point, dp[j]);
		}
		//1에서 증가가 있다는 뜻 즉 +1
		dp[i] = point + 1;
		result = max(result, dp[i]);
	}
	printf("%d\n", result);
	
	//메모리 해제
	free(dp);
	free(arr);

	return 0;
}