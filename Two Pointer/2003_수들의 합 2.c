#include "stdio.h"
#include "stdlib.h"

int main(void) {
	int n; //배열의길이	
	long long m; //타겟
	int answer = 0;

	scanf("%d %lld", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * n);
	//배열 입력
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	//투 포인터 알고리즘
	int start = 0, end = 0;
	int partial_tot = 0;
	

	while (end<=n) {
		if (partial_tot == m)
			answer++;
		//부분합이 타겟보다 작으면
		if (partial_tot < m)
			//end 증가
			partial_tot += arr[end++];
		else if (partial_tot >= m)
			partial_tot -= arr[start++];
	}
	printf("%d", answer);
	return 0;
}