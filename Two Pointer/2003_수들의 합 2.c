#include "stdio.h"
#include "stdlib.h"

int main(void) {
	int n; //�迭�Ǳ���	
	long long m; //Ÿ��
	int answer = 0;

	scanf("%d %lld", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * n);
	//�迭 �Է�
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	//�� ������ �˰���
	int start = 0, end = 0;
	int partial_tot = 0;
	

	while (end<=n) {
		if (partial_tot == m)
			answer++;
		//�κ����� Ÿ�ٺ��� ������
		if (partial_tot < m)
			//end ����
			partial_tot += arr[end++];
		else if (partial_tot >= m)
			partial_tot -= arr[start++];
	}
	printf("%d", answer);
	return 0;
}