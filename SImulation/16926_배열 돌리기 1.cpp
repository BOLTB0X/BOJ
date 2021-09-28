#include <iostream>

using namespace std;

int n, m, r;
int arr[301][301] = { 0, };

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

void rotate(void) {
	while (r--) {
		int y1 = 0, x1 = 0;
		int y2 = 0, x2 = m-1;
		int y3 = n-1, x3 = m-1;
		int y4 = n-1, x4 = 0;

		while (y1 < y4 && x1 < x2) {
			int tmp = arr[y1][x1];
			for (int i = x1; i < x2; i++) {
				arr[y1][i] = arr[x1][i + 1];
			}
			for (int i = y2; i < y3; i++) {
				arr[i][x2] = arr[i+1][x2];
			}
			for (int i = x3; i > x4; i--) {
				arr[y3][i] = arr[y3][i - 1];
			}
			for (int i = y4; i > y1; i--) {
				arr[i][x4] = arr[i-1][x4];
			}
			arr[y1 + 1][x4] = tmp;
			y1 += 1;
			x1 += 1;
			y2 += 1;
			x2 -= 1;
			y3 -= 1;
			x3 -= 1;
			y4 -= 1;
			x4 += 1;
		}
	}
}

void print_arr(void) {
	for (int y = 0; y < n; y++) 
		for (int x = 0; x < m; x++) 
			cout << arr[y][x] << " ";
		cout << '\n';
	return;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> arr[y][x];
		}
	}
	rotate();
	print_arr();
	return 0;
}