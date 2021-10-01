#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n) {
	if (n == 0 || n == 1)
		return false;
	for (int i = 2; i < (int)(sqrt(n) + 1); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void) {
	int n, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int number;
		scanf("%d", &number);
		if (is_prime(number))
			result++;
	}
	printf("%d\n", result);
	return 0;
}