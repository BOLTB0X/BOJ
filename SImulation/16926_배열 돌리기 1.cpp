#include <iostream>

using namespace std;

int arr[301][301];

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

// 회전
void arr_rotate(int n, int m) {
	int max_cnt = Min(n, m) / 2; // 돌리는 횟수

	for (int cnt = 0; cnt < max_cnt; ++cnt) {
		int max_n = n - cnt - 1;
		int max_m = m - cnt - 1;
		int tmp = arr[cnt][cnt];

		// 윗 변: <-
		for (int i = cnt; i < max_m; ++i)
			arr[cnt][i] = arr[cnt][i + 1];

		// 오른쪽 변
		for (int i = cnt; i < max_n; ++i)
			arr[i][max_m] = arr[i + 1][max_m];

		// 아래 변: ->
		for (int i = max_m; i > cnt; --i)
			arr[max_n][i] = arr[max_n][i - 1];

		// 왼쪽 변
		for (int i = max_n; i > cnt; --i)
			arr[i][cnt] = arr[i - 1][cnt];

		arr[cnt + 1][cnt] = tmp;
	}
	return;
}

void solution(int n, int m, int r) {
	while (r--)
		arr_rotate(n, m);
	return;
}

int main(void) {
	int n, m, r;

	cin >> n >> m >> r;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	}

	solution(n, m, r);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
