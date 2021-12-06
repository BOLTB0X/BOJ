#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int two_pointer(int n) {
	int cnt = 0;
	int left = 1, right = 2;
	int partial_tot = 1;

	while (right <= n) {
		partial_tot += right;

		if (partial_tot == n) {
			cnt++;
			partial_tot = 0;
			left++;
			right = left;
		}

		else if (partial_tot < n)
			right++;

		else if (partial_tot > n) {
			partial_tot = 0;
			left++;
			right = left;
		}
	}

	return cnt;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	int ret = two_pointer(n);

	printf("%d\n", ret);

	return;
}

int main(void) {
	solution();
	return 0;
}