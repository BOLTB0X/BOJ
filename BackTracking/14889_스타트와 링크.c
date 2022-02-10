#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n;
int result = 0x7fffffff;
int board[21][21];
int visited[21];

int MIN(int a, int b) {
	return a < b ? a : b;
}

int abs(int a) {
	return a < 0 ? -a : a;
}

void check_gap(void) {
	int start = 0, link = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i] == 1 && visited[j] == 1)
				start += board[i][j];
			if (visited[i] == 0 && visited[j] == 0)
				link += board[i][j];
		}
	}

	result = MIN(result, abs(start - link));
	return;
}

void DFS(int cur, int level) {
	if (level == n / 2) {
		check_gap();
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		DFS(i + 1, level + 1);
		visited[i] = 0;
	}

	return;
}

int solution(void) {
	int answer = 0;
	memset(visited, 0, sizeof(int) * 21);

	DFS(0, 0);
	answer = result;
	return answer;
}

int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i][j]);
	}

	int ret = solution();
	printf("%d", ret);

	return 0;
}