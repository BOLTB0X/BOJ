#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];

	scanf("%[^\n]s", str);

	for (int i = 0; i < strlen(str); ++i) {
		//소문자
		if (str[i] >= 'a' && str[i] <= 'z') {
			int tmp = (str[i] - 'a' + 13) % 26;
			char st = (char)tmp + 'a';
			printf("%c",st);
		}

		//대문자
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