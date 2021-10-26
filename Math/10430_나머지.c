#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int ans1 = (a + b) % c;
	int ans2 = ((a % c) + (b % c)) % c;
	int ans3 = (a * b) % c;
	int ans4 = ((a % c) * (b % c)) % c;

	printf("%d\n", ans1);
	printf("%d\n", ans2);
	printf("%d\n", ans3);
	printf("%d\n", ans4);

	return 0;
}