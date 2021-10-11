#include <stdio.h>

int main(void) {
	int n;
	int idx = 1;
	int result = 0;

	scanf("%d", &n);

	while (idx <= n) {
		//1ÀÇ ÀÚ¸®
		result += (n - idx + 1);
		idx = idx * 10;
	}

	printf("%d\n", result);
	return 0;
}