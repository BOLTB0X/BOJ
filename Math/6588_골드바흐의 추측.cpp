#include <iostream>
#include <vector>

using namespace std;

vector<int> prime(1000001, 0);
vector<int> prime_v;

void eratos(void) {
	prime[0] = prime[1] = 1;

	for (int i = 2; i * i < 1000001; ++i) {
		// 소수 발견
		if (prime[i] == 0) 
			prime_v.push_back(i);
		
		for (int j = i + i; j < 1000001; j += i)
			prime[j] = 1;
	}
	return;
}

void solution(int n) {
	int p1 = 0;
	int p2 = 0;

	for (int i = 0; i < prime_v.size(); ++i) {
		// 발견
		if (prime[n - prime_v[i]] == 0) {
			p1 = prime_v[i];
			p2 = n - prime_v[i];
			break;
		}
	}
	printf("%d = %d + %d\n", n, p1, p2);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;

	eratos(); // 먼저 소수 구별
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		solution(n);
	}

	return 0;
}
