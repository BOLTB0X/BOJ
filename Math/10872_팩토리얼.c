#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N;
	int answer = 1;

	scanf("%d", &N);
	for (int i = N; i > 0; --i) 
		answer *= i;
	
	printf("%d\n", answer);
	return 0;
}