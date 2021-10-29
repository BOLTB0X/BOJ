#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result;

//깊이우선탐색
void DFS(int n, int tot) {
	//넘길시
	if (tot > n)
		return;
	if (tot == n)
		result++;
	for (int i = 1; i <= 3; ++i)
		DFS(n, tot + i);
	return;
}

int main(void) {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);

		//초기화 및 호출
		result = 0;
		DFS(n, 0);
		
		printf("%d\n", result);
	}
	return 0;
}