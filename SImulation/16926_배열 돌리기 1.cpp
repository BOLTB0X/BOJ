#include <iostream>

using namespace std;

int n, m, r;
int arr[301][301] = { 0, };

//회전방향
void arr_rotate(void) {
	while (r--) {
		int y1 = 0;
		int x1 = 0;

		int y2 = n - 1;
		int x2 = 0;

		int y3 = n - 1;
		int x3 = m - 1;

		int y4 = 0;
		int x4 = m - 1;

		//시뮬시작
		while ((y1 < y2) && (x1 < x4)) {
			int tmp = arr[y2][x2];
			//상
			for (int i = y2; i > y1; i--) {
				arr[i][x2] = arr[i - 1][x2];
			}
			//좌
			for (int j = x1; j < x4; j++) {
				arr[y1][j] = arr[y1][j + 1];
			}
			//하
			for (int i = y4; i < y3; i++) {
				arr[i][x4] = arr[i + 1][x4];
			}
			//우
			for (int j = x3; j > x2; j--) {
				arr[y3][j] = arr[y3][j-1];
			}
			arr[y2][x2 + 1] = tmp;
			y1 += 1;
			x1 += 1;
			
			y2 -= 1;
			x2 += 1;
			
			y3 -= 1;
			x3 -= 1;
			
			y4 += 1;
			x4 -= 1;
		}
	}
}

void print_arr(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	arr_rotate();
	print_arr();
	return 0;
}
