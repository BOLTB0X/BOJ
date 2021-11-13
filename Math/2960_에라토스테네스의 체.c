#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;
//배열 초기화
int arr[1001] = { 0, };

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);

	//셋팅
	for (int i = 1; i <= n; ++i)
		arr[i] = i;

	//에라토스테네스의 체 시작
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		//i를 2부터 시작하여 배수를 차례로 지움
		for (int j = i; j <= n; j += i) {
			if (arr[j] != 0) {
				arr[j] = 0;
				//몇개 지웠는지 체크
				cnt++;

				//cnt 변수가 k와 같아지는 순간이 k번째 지워진 수
				if (cnt == k) {
					printf("%d\n",j);
					return 0;
				}
			}
		}
	}
}