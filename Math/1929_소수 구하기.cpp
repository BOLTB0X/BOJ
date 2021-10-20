#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
	if (n == 1 || n == 0)
		return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void solution(void) {
	int N, M;

	cin >> N >> M;

	for (int i = N; i <= M; ++i) {
		if (is_prime(i))
			cout << i << '\n';
	}
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