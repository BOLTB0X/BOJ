#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int d = 2;

	while (n!=1) {
		if (n % d == 0) {
			n /= d;
			printf("%d\n", d);
		}
		else
			d++;
	}

	return 0;
}