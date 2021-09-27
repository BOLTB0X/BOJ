#include <stdio.h>

int n;
int max_value;
int arr[1000][5];
int score[1000];

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

//최대값 찾기
void find_max_value(void) {
	max_value = -1;
	//4중 for문 이용
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				for (int l = k + 1; l < 5; l++) {
					score[i] = max(score[i], (arr[i][j] + arr[i][k] + arr[i][l]) % 10);
				}
			}
		}
		max_value = max(max_value, score[i]);
	}
	return;
}

//승자 찾기
int find_winner(void) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (score[i] == max_value)
			answer = i + 1;
	}
	return answer;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//최대 값 순회
	
	find_max_value();
	int ret = find_winner();

	printf("%d\n", ret);
	return 0;
}