#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//�ִ밪 ����
#define MAX 1000000

//���ڹ迭 ����
int numbers[MAX] = { 0, };

//����
void init(void) {
	//������ 
	numbers[0] = numbers[1] = 1;
	for (int i = 2; i <= (int)sqrt(MAX); ++i) {
		for (int j = i * i; j <= MAX; j += i) {
			//1�̸� �Ҽ��� �ƴ�
			if (numbers[j] % i == 0)
				numbers[j] = 1;
		}
	}
	return;
}

int main(void) {
	//������ ������ ���� ����
	init();

	int T;
	scanf("%d", &T);
	
	while (T--) {
		int n;
		scanf("%d", &n);
		
		//��Ƽ�� ���ϱ�
		for (int i = n / 2; i > 0; i--) {
			if (numbers[i] != 1 && numbers[n - i] != 1) {
				printf("%d %d\n", i, n - i);
				break;
			}
		}
	}

	return 0;
}