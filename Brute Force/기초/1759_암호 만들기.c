#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[15];
char str[15];
int visited[15] = { 0, };

int compare(const void* a, const void* b) {
	return strcmp((char*)a, (char*)b);
}

void check_Voca(int L, int C) {
	int j_cnt = 0;
	int m_cnt = 0;

	for (int i = 0; i < C; ++i) {
		if (visited[i] == 1) {
			if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
				m_cnt++;
			else
				j_cnt++;
		}
	}

	if (j_cnt >= 2 && m_cnt >= 1) {
		for (int i = 0; i < C; ++i) {
			if (visited[i] == 1)
				printf("%c", input[i]);
		}
		printf("\n");
	}
	return;
}

void DFS(int L, int C, int cur, int level) {
	if (level == L) {
		check_Voca(L, C);
		return;
	}

	for (int i = cur; i < C; ++i) {
		if (visited[i])
			continue;
		visited[i] = 1;
		DFS(L, C, i + 1, level + 1);
		visited[i] = 0;
	}
	return;
}

void solution(int L, int C) {
	qsort(input, C, sizeof(char), compare);
	memset(visited, 0, sizeof(int) * C);

	DFS(L, C, 0, 0);

	return;
}

int main(void) {
	int l,c;
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; ++i)
		scanf(" %c", &input[i]);
	
	solution(l, c);
	return 0;
}