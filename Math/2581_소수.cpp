#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//소수판별
bool is_prime(int n) {
	if (n == 0 || n == 1)
		return false;

	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

//합
int tot(vector<int>& v) {
	int tot = 0;
	for (int i = 0; i < v.size(); ++i)
		tot += v[i];

	return tot;
}

void solution(void) {
	int M, N;
	vector<int> result;

	cin >> M;
	cin >> N;

	//소수탐색
	for (int num = M; num <= N; ++num) {
		if (is_prime(num))
			result.push_back(num);
	}

	if (result.size() == 0)
		cout << -1 << '\n';
	else {
		cout << tot(result) << '\n';
		cout << result[0] << '\n';
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}