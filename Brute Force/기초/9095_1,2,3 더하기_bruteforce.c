#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result = 0;

void DFS(int n, int tot, int level) {
	if (tot == n) {
		result++;
		return;
	}

	if (tot > n)
		return;

	for (int i = 1; i <= 3; ++i)
		DFS(n, tot + i, level + 1);
	return;
}

void solution(int T) {
	int n;

	while (T--) {
		result = 0;
		scanf("%d", &n);
		DFS(n, 0, 0);
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
