#include <iostream>
#include <cmath>
#include <vector>
#define MAX_LEN 1000001

using namespace std;

vector<long long> dp;
vector<long long> div_tot;

void get_Divisor_tot(void) {
	for (int i = 2; i < MAX_LEN; ++i) {
		for (int j = 1; i * j < MAX_LEN; ++j)
			div_tot[i * j] += i;
	}

	for (int i = 1; i < MAX_LEN; ++i) 
		dp[i] = dp[i - 1] + div_tot[i];

	return;
}

void solution(int T) {
	int number;
	dp.resize(MAX_LEN, 0);
	div_tot.resize(MAX_LEN, 1);

	get_Divisor_tot();

	while (T--) {
		cin >> number;

		cout << dp[number] << '\n';
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	solution(T);
	return 0;
}