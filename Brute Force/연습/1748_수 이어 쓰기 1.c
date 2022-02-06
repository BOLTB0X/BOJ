#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, idx = 1, result = 0;

	scanf("%d", &n);

	while (idx <= n) {
		result += (n - idx + 1);
		idx *= 10;
	}

	printf("%d", result);

	return 0;
}
