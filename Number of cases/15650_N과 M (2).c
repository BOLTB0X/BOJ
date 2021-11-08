#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//���̿켱Ž���� �̿��� ��Ʈ��ŷ
void DFS(int* com, int n, int m, int depth) {
	//Ž��
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

		//���
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

	//�����Ҵ�
	int* com = malloc(sizeof(int) * (n + 1));

	//�ʱ�ȭ
	for (int i = 0; i < n; ++i)
		com[i] = 0;

	DFS(com, n, m, 0);

	//�޸� ����
	free(com);

	return 0;
}