#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
	if (n == 0 || n == 1)
		return 0;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = N; i <= M; ++i) {
		if (is_prime(i) == 1)
			printf("%d\n", i);
	}
	return 0;
}