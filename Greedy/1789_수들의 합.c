#include "stdio.h"

int main(void) {
	long long S;
	//입력
	scanf("%lld", &S);

	long long tot = 0;
	int answer = 0;
	//1부터 시작
	int number = 1;
	
	while(1) {
		tot += number;
		answer++;
		//탈출조건
		//S보다 커지는지 검사
		if (tot > S) {
			answer--;
			break;
		}
		number++;
	}
	printf("%d", answer);
	return 0;
}
