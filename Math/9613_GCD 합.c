#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int* arr = malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		long long tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				tot += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", tot);
		free(arr);
	}
	
	return 0;
}