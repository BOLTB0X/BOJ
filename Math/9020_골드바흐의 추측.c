#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//최대값 셋팅
#define MAX 1000000

//숫자배열 셋팅
int numbers[MAX] = { 0, };

//셋팅
void init(void) {
	//골드바흐 
	numbers[0] = numbers[1] = 1;
	for (int i = 2; i <= (int)sqrt(MAX); ++i) {
		for (int j = i * i; j <= MAX; j += i) {
			//1이면 소수가 아님
			if (numbers[j] % i == 0)
				numbers[j] = 1;
		}
	}
	return;
}

int main(void) {
	//골드바흐 추측을 위한 셋팅
	init();

	int T;
	scanf("%d", &T);
	
	while (T--) {
		int n;
		scanf("%d", &n);
		
		//파티션 구하기
		for (int i = n / 2; i > 0; i--) {
			if (numbers[i] != 1 && numbers[n - i] != 1) {
				printf("%d %d\n", i, n - i);
				break;
			}
		}
	}

	return 0;
}