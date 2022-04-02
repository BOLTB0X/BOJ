#include <iostream>
#define LL long long

using namespace std;

LL com[31][31];

// 보텀업
void do_dynamic(void) {
	for (int i = 1; i < 30; ++i) {
		com[i][i] = 1;
		com[i][1] = i;
	}

	// 조합의 성질
	for (int i = 2; i < 30; ++i) {
		for (int j = 2; j < 30; ++j) {
			if (i > j)
				com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
		}
	}
	return;
}

int main(void) {
	int T;
	int n, m;

	cin >> T;
	do_dynamic();
	while (T--) {
		cin >> n >> m;
		cout << com[m][n] << '\n';
	}

	return 0;
}