#include <iostream>
#include <vector>
#define mod 1000000000

using namespace std;

vector<vector<int>> dp(101, vector<int> (10, 0));

int solution(int n) {
    int result = 0;

	for (int i = 1; i < 10; ++i) 
		dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= mod;
        }
    }

    for (int i = 0; i < 10; i++) 
        result = (result + dp[n][i]) % mod;
    
    return result;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int ret = solution(n);
	cout << ret;
	return 0;
}