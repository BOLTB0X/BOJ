#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n;
	int arr[1001];
	//수열 입력
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &arr[i]);
	int result = -1;	
	int max_value = 0;
	//탐색으로 오르막길 확인
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i + 1]) {
			max_value += (arr[i + 1] - arr[i]);
		}
		else {
			result = max(result, max_value);
			max_value = 0;
		}
	}
	//마지막 한발
	result = max(result, max_value);
	printf("%d", result);
	return 0;
}