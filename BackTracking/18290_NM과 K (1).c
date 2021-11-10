#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int board[10][10];
bool visited[10][10] = { false, };
int result = -0x7fffffff;

//��������
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

//�ִ񰪿���
int max(int a, int b) {
	return a > b ? a : b;
}

//���̿켱Ž������ ����Ž��
void DFS(int n, int m, int k, int depth, int tot) {
	//Ż������
	if (k == depth) {
		result = max(result, tot);
		return;
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			//��湮�� ���
			if (visited[y][x])
				continue;
			
			bool flag = true;
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				//�����ʰ�
				if (nx < 0 || ny < 0 || ny >= n || nx >= m)
					continue;
				if (visited[ny][nx])
					flag = false;
			}
			if (flag == true) {
				visited[y][x] = true;
				DFS(n, m, k, depth + 1, tot + board[y][x]);
				visited[y][x] = false;
			}
		}
	}
	return;
}

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	//�Է�
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			scanf("%d",&board[i][j]);
	}

	//��Ʈ��ŷ ����
	DFS(n, m, k, 0, 0);
	
	//���
	printf("%d\n", result);
	return 0;
}