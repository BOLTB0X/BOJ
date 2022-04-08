#include <iostream> 

using namespace std;

int cnt[10001] = {0, };

void solution(int n) {
	for (int i = 1; i < 10001; ++i) {
		if (cnt[i] > 0) {
			for (int j = 0; j < cnt[i]; ++j)
				cout << i << '\n';
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, tmp;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		cnt[tmp]++;
	}
	
	solution(n);

	return 0; 
}
