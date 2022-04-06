#include <iostream>
#include <cstring>

using namespace std;

int board[101][101];

int main(void) {
	int n, tot = 0;

	cin >> n;
	memset(board, 0, n);
	for (int i = 0; i < n; ++i) {
		int y, x;

		cin >> x >> y;
		for (int i = y; i < y + 10; ++i) {
			for (int j = x; j < x + 10; ++j)
				board[i][j] = 1;
		}
	}

	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j)
			tot += board[i][j];
	}

	cout << tot;
	return 0;
}