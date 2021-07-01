#include <iostream>
using namespace std;
int T,n,m;

void solution(void) {
	cin >> T;
	while (T != 0) {
		int answer = 0;
		cin >> n >> m;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (!((i * i + j * j + m) % (i * j)))
					answer += 1;
			}
		}
		cout << answer << '\n';
		T--;
	}
}

int main(void) {
	solution();
	return 0;
}