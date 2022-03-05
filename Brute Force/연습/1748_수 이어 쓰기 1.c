#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, idx = 1, result = 0;

	scanf("%d", &n);
	
	//1, 10, 100이므로
	while (idx <= n) {
		result += (n - idx + 1);  //현재 idx랑 비교
		idx *= 10; //10씩 곱해줌
	}

	printf("%d", result);

	return 0;
}
