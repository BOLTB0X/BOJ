#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result;

void DFS(int number, int tot) {
	if (tot > number)
		return;
	if (tot == number)
		result++;

	for (int i = 1; i <= 3; ++i)
		DFS(number, tot + i);

	return;
}

int main(void) {
	int T;
	scanf("%d", &T);

	while (T--) {
		int number;
		scanf("%d", &number);

		result = 0;
		DFS(number, 0);
		printf("%d\n", result);
	}

	return 0;
}
