#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int board[25][25];
int visited[25][25] = { 0, };
int result[625] = { 0, };

//�����¿�
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//������
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

//������
void quick_sort(int start, int end) {
	//���Ұ� �ϳ��ų� ��������
	if (start >= end)
		return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	//������������
	while (left <= right) {
		while (left <= end && result[left] <= result[pivot])
			left++;
		while (right > start && result[right] >= result[pivot])
			right--;

		if (left > right)
			swap(&result[pivot], &result[right]);
		else
			swap(&result[left], &result[right]);
	}
	quick_sort(start, right - 1);
	quick_sort(right + 1, end);

	return;
}

//���̿켱Ž��
void DFS(int y, int x, int len) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//������
		if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
			//�̹湮�̰� ����Ʈ�� �߰��ϸ�
			if (visited[ny][nx] == 0 && board[ny][nx] != 0) {
				visited[ny][nx] = 1;
				result[len] += 1;
				DFS(ny, nx, len);
			}
		}
	}
	return;
}

void solution(void) {
	int len = 0;
	//�Է�
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &board[i][j]);
		}
	}
	
	//����ƮŽ�� ����
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//�̹湮�̰� ����Ʈ�� �߰��Ѵٸ�
			if (visited[i][j] == 0 && board[i][j] != 0) {
				visited[i][j] = 1;
				result[len] = 1;
				DFS(i, j, len);
				len++;
			}
		}
	}
	//�������� ����
	quick_sort(0, len - 1);

	//���
	printf("%d\n", len);
	for (int i = 0; i < len; ++i) 
		printf("%d\n", result[i]);
	
	return;
}

int main(void) {
	solution();
	return 0;
}