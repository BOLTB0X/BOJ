#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int visited[10];

int min(int a, int b) {
	return a < b ? a : b;
}

int abs(int a) {
	return a < 0 ? -a : a;
}

int get_number_length(int number) {
	int cnt = 0;

	if (number == 0) 
		return 1;
	
	while (number != 0) {
		number /= 10;
		++cnt;
	}
	return cnt;
}

int is_broken(int number) {
	int div = 10;
	if (number == 0) {
		if (visited[0] == 1)
			return 0;
	}

	while (number != 0) {
		int d = number % div;
		if (visited[d] == 1)
			return 0;
		number /= div;
	}

	return 1;
}

int solution(int n) {
	int answer = abs(n - 100);

	for (int i = 0; i <= 1000000; ++i) {
		if (is_broken(i) == 1) {
			int tmp = abs(n - i) + get_number_length(i);
			answer = min(answer, tmp);
		}
	}
	return answer;
}

int main(void) {
	int n;
	int m, broken;
	scanf("%d", &n);
	scanf("%d", &m);

	memset(visited, 0, sizeof(int) *10);

	for (int i = 0; i < m; ++i) {
		scanf("%d", &broken);
		visited[broken] = 1;
	}
	if (m > 9) 
		printf("%d", abs(n - 100));
	else {
		int ret = solution(n);
		printf("%d", ret);
	}
	return 0;
}