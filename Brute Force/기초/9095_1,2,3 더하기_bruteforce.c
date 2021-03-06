#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result = 0;

void DFS(int n, int tot) {
	//카운트 조건
	if (n == tot) {
		result++;
		return;
	}

	// 조건을 넘겼을때
	if (tot > n)
		return;

	for (int i = 1; i <= 3; ++i)
		DFS(n, tot + i);
	return;
}

void solution(int T) {
	int n;
	while (T--) {
		result = 0; //초기화

		scanf("%d", &n);
		//DFS로 탐색
		DFS(n, 0);

		printf("%d\n", result);
	}
	return;
}

int main(void) {
	int T;
	scanf("%d", &T);

	solution(T);

	return 0;
}
