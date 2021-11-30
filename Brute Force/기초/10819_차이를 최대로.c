#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int result = -1;
int per[9] = { 0, };

//���� ��ȯ
int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

//�� ���̰�
int get_dist(int n) {
	int tot = 0;
	for (int i = 0; i < n - 1; ++i)
		tot += abs(per[i] - per[i + 1]);

	return tot;
}

//���̿켱Ž��
void DFS(int n, int* arr, int* visited, int depth) {
	//Ż������
	if (depth == n) {
		//�ִ� ��ü
		if (result < get_dist(n))
			result = get_dist(n);
		return;
	}

	//����
	for (int i = 0; i < n; ++i) {
		//����ó��
		if (visited[i] == 1)
			continue;
		per[depth] = arr[i];
		visited[i] = 1;
		DFS(n, arr, visited, depth + 1);
		visited[i] = 0;
	}

	return;
}

//�ذ��Լ�
void solution(int n, int* arr) {
	//�湮����Ʈ
	int* visited = malloc(sizeof(int) * n);
	
	//���� �Է�
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		visited[i] = 0;
	}

	//DFS�� ����
	DFS(n, arr, visited, 0);

	//���
	printf("%d\n", result);

	//����
	free(visited);
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	//�����Ҵ�
	int* arr = malloc(sizeof(int) * n);

	//�ʱ�ȭ
	for (int i = 0; i < n; ++i)
		arr[i] = 0;

	//�ذ�
	solution(n,arr);

	//����
	free(arr);
	return 0;
}