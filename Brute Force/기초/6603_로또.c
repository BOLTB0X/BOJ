#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int com[6];
int arr[13];

//±íÀÌ ¿ì¼± Å½»ö 
void DFS(int n, int cur, int dep) {
	if (dep == 6) {
		for (int i = 0; i < 6; ++i)
			printf("%d ", com[i]);
		printf("\n");
		return;
	}

	for (int i = cur; i < n; ++i) {
		com[dep] = arr[i];
		DFS(n, i + 1, dep + 1);
	}
	return;
}

int main(void) {
	int n;
	while (1) {
		scanf("%d", &n);

		if (n == 0)
			break;	
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		
		DFS(n, 0, 0);
		printf("\n");
	}
	return 0;
}