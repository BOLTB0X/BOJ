#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int result = 0;

void DFS(int* arr, int len, int target, int idx, int tot) {
	if (idx == len)
		return;
	if (tot + arr[idx] == target)
		result++;

	DFS(arr, len, target,idx + 1, tot);
	DFS(arr, len, target, idx + 1, tot + arr[idx]);
}

int main(void) {
	int n, target;
	scanf("%d %d", &n, &target);

	//�����Ҵ�
	int* arr = malloc(sizeof(int) * (n));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	DFS(arr, n, target, 0, 0);

	printf("%d\n", result);
	
	//�޸� ����
	free(arr);
	return 0;
}