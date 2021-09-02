#include "stdio.h"

int main(void) {
	long long S;
	scanf("%lld", &S);

	long long tot = 0;
	int answer = 0;
	int number = 1;

	while(1) {
		tot += number;
		answer++;
		if (tot > S) {
			answer--;
			break;
		}
		number++;
	}
	printf("%d", answer);
	return 0;
}