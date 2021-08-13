#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int n, m;
bool visited[9];
int com[9];

void combination(int n, int m, int depth, int cur) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", com[i]);
		}
		printf("\n");
		return;
	}
	for (int i = cur; i <= n; i++) {
		if (visited[i]) 
			continue;
		visited[i] = true;
		com[depth]=i;
		combination(n, m, depth + i,cur+1);
		visited[i] = false;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	combination(n, m, 0, 1);
	return 0;
}