#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//���̿켱Ž���� �̿��� ��Ʈ��ŷ
void DFS(int* per, int n, int m, int depth) {
	//Ž��
	for (int i = 1; i <= n; i++) {
		int k = 0;

		if (depth == 0)
			per[0] = i;

		else {
			for (k = 0; k < depth; k++) {
				if (per[k] == i) 
					break;
			}

			if (k == depth) 
				per[depth] = i;
			
			else 
				continue;
		}

		//���
		if (m - 1 == depth) {
			for (int k = 0; k < m; k++)
				printf("%d ", per[k]);
			printf("\n");
		}

		else 
			DFS(per,n, m, depth + 1);
	}
	return;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	//�����Ҵ�
	int* per = malloc(sizeof(int) * (n + 1));
	int* visited = malloc(sizeof(int) * (n + 1));

	//�ʱ�ȭ
	for (int i = 0; i < n; ++i)
		per[i] = 0;
	
	DFS(per, n, m, 0);

	//�޸� ����
	free(per);
	free(visited);

	return 0;
}