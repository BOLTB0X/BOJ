#include <iostream>

using namespace std;

int arr[300][300];

//시뮬레이션
void arr_rotate(int n, int m, int r) {
	while (r--) {
		int y1 = 0, x1 = 0;
		int y2 = n - 1, x2 = 0;
		int y3 = n - 1, x3 = m - 1;
		int y4 = 0, x4 = m - 1;

		while ((y1 < y2) && (x1 < x4)) {
			int tmp = arr[y2][x2];
			
			// 상
			for (int i = y2; i > y1; --i)
				arr[i][x2] = arr[i - 1][x2];

			// 좌
			for (int i = x1; i < x4; ++i)
				arr[y1][i] = arr[y1][i + 1];

			// 하
			for (int i = y4; i < y3; ++i)
				arr[i][x4] = arr[i + 1][x4];

			// 우
			for (int i = x3; i > x2; --i)
				arr[y3][i] = arr[y3][i - 1];

			arr[y2][x2 + 1] = tmp;
			y1++, x1++;
			y2--, x2++;
			y3--, x3--;
			y4++, x4--;
		}
	}
	
	return;
}

//해결
void solution(int n, int m, int r) {
	//시뮬레이션 시작
	arr_rotate(n, m, r);

	return;
}

int main(void) {
	int n, m, r;

	//입력
	cin >> n >> m >> r;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cin >> arr[y][x];
		}
	}

	solution(n, m, r);

	//출력
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cout << arr[y][x] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
