#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(char vps[]) {
	char* answer = malloc(sizeof(char) * (strlen(vps) + 1));
	int cnt = 0;
	memset(answer, '\0', strlen(vps) + 1);
	strcpy(answer, "YES");
	
	for (int i = 0; i < strlen(vps); ++i) {
		if (vps[i] == '(')
			cnt++;
		// 닫음일때
		else {
			cnt--;

			if (cnt < 0) {
				strcpy(answer, "NO");
				break;
			}

		}
	}
	// 스택이 비어있지 않다면
	if (cnt != 0) 
		strcpy(answer, "NO");

	return answer;
}

int main(void) {
	int T;

	scanf("%d", &T);
	while (T--) {
		char vps[51] = { '\0', };
		scanf("%s", &vps);

		char* ret = solution(vps);
		printf("%s\n", ret);
	}
	return 0;
}