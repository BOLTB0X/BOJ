#include <iostream>

using namespace std;

int answer = 0;
bool check_list[201][201] = { false, };

void solution(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		check_list[a][b] = true;
		check_list[b][a] = true;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (check_list[i][j])
				continue;
			for (int k = j + 1; k <= n; ++k) {
				if (check_list[i][k] || check_list[j][k])
					continue;
				answer++;
			}
		}
	}

	cout << answer << '\n';
	return;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}