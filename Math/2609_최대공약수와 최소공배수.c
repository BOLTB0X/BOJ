#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a% b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main(void) {
	int a, b;

	scanf("%d %d", &a, &b);
	int ret1 = gcd(a, b);
	int ret2 = lcm(a, b);

	printf("%d\n", ret1);
	printf("%d\n", ret2);
	return 0;
}