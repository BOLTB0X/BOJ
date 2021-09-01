#include "stdio.h"
#include "math.h"

int main(void) {
	char N[37];
	int B;

	scanf("%s", N);
	int N_size = strlen(N);
	scanf("%d", &B);

	int cnt = 0;
	int answer = 0;
	for (int i = N_size - 1; i >= 0; i--) {
		int tmp = N[i];
		if (tmp >= 'A' && tmp <= 'Z')
			answer += (tmp - 'A' + 10) * ((int)pow(B, cnt));
		else
			answer += (tmp - '0') * ((int)pow(B, cnt));
		cnt++;
	}
	printf("%d\n", answer);
	return 0;
}