#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int arr[1000][5];
	int score[1000] = {0,};

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	int max_value = -1;
	///완전 탐색 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				for (int l = k + 1; l < 5; l++) {
					score[i] = max(score[i], (arr[i][j] + arr[i][k] + arr[i][l]) % 10);
				}
			}
		}
		max_value = max(score[i], max_value);
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (score[i] == max_value) {
			idx = i + 1;
		}
	}
	cout << idx << '\n';
	return 0;
}