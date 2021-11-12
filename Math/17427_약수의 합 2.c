#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	long long result = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		result += (n / i) * i;

	printf("%lld\n", result);
	return 0;
}