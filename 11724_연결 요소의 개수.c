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
	
	//�Է�
	scanf("%d %d", &n, &m);

	//�׷��� �Է�
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	//�� ������ �̹湮�� ��쿡�� DFSŽ��
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			DFS(n, i);
			result++;
		}
	}
	//���
	printf("%d\n", result);
	return 0;
}