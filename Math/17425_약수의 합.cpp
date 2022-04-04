#include <iostream>
#include <vector>
#define LL long long
#define Max_Size 1000001

using namespace std;

vector<long long> dp;
vector<long long> divisor_tot;

void do_dynamic(void) {
	dp.resize(Max_Size, 0);
	divisor_tot.resize(Max_Size, 1); // 1은 항상 있으므로

	dp[1] = 1; // 1
	for (LL i = 2; i < Max_Size; ++i) {
		for (LL j = 1; j * i < Max_Size; ++j)
			divisor_tot[i * j] += i;
		dp[i] = dp[i - 1] + divisor_tot[i];
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, n;

	cin >> T;
	do_dynamic();
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
