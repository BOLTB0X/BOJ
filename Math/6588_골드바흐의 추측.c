#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int prime[1000001];
int p_idx = 0;
int check[1000001] = { 0, };

void solution(void) {
	int num;

	for (int i = 2; i*i < 1000001; ++i) {
		if (check[i] == 0) {
			prime[p_idx++] = i;

			for (int j = i + i; j < 1000001; j += i) {
				check[j] = 1;
			}
		}
	}
	while (1) {
		int flag = 0;
		int p1, p2;
	
		scanf("%d", &num);
		if (num <= 4)
			break;
		for (int i = 0; i < p_idx; ++i) {
			if (check[num - prime[i]] == 0) {
				p1 = prime[i];
				p2 = num - prime[i];
				flag = 1;
				break;
			}

		}

		if (flag == 0)
			printf("Goldbach's conjecture is wrong.\n");
		else {
			printf("%d = %d + %d\n", num, p1, p2);
		}
	}

	return;
}

int main(void) {
	solution();
	return 0;
}