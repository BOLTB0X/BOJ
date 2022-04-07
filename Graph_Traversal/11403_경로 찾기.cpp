#include <iostream>
#include <vector>

using namespace std;

int adj[101][101];

void solution(int n) {
	// 플로이드 와샬
	for (int k = 0; k < n; ++k) {
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b)
				if (adj[a][k] != 0 && adj[k][b] != 0)
					adj[a][b] = 1;
		}
	}
	return;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> adj[i][j];
	}

	solution(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << adj[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}