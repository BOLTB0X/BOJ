#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];

	scanf("%[^\n]s", str);

	for (int i = 0; i < strlen(str); ++i) {
		//�ҹ���
		if (str[i] >= 'a' && str[i] <= 'z') {
			int tmp = (str[i] - 'a' + 13) % 26;
			char st = (char)tmp + 'a';
			printf("%c",st);
		}

		//�빮��
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			int tmp = (str[i] - 'A' + 13) % 26;
			char st = (char)tmp + 'A';
			printf("%c", st);
		}

		else
			printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}