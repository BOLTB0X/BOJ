#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int graph[1001][1001];
int visited[1001] = { 0 };

void DFS(int n, int start) {
	visited[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && graph[start][i] == 1)
			DFS(n, i);
	}
}

int main(void) {
	int n, m, result = 0;
	
	//입력
	scanf("%d %d", &n, &m);

	//그래프 입력
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	//각 정점이 미방문일 경우에만 DFS탐색
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			DFS(n, i);
			result++;
		}
	}
	//출력
	printf("%d\n", result);
	return 0;
}