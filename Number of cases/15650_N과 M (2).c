#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//깊이우선탐색을 이용한 백트래킹
void DFS(int* com, int n, int m, int depth) {
	//탐색
	for (int i = 1; i <= n; i++) {
		int k = 0;

		if (depth == 0)
			com[0] = i;

		else {
			for (k = 0; k < depth; k++) {
				if (com[k] >= i)
					break;
			}

			if (k == depth)
				com[depth] = i;

			else
				continue;
		}

		//출력
		if (m - 1 == depth) {
			for (int k = 0; k < m; k++)
				printf("%d ", com[k]);
			printf("\n");
		}

		else
			DFS(com, n, m, depth + 1);
	}
	return;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	//동적할당
	int* com = malloc(sizeof(int) * (n + 1));

	//초기화
	for (int i = 0; i < n; ++i)
		com[i] = 0;

	DFS(com, n, m, 0);

	//메모리 해제
	free(com);

	return 0;
}