#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//유클리드 호제법
int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main(void) {
	int N, S;

	scanf("%d %d", &N, &S);

	int gcd_value = -1;
	while (N--) {
		int a;
		scanf("%d", &a);

		int dist = (S > a) ? (S - a) : (a - S);
		if (gcd_value != -1)
			gcd_value = gcd(gcd_value, dist);

		else
			gcd_value = dist;
	}

	printf("%d\n", gcd_value);
	return 0;
}