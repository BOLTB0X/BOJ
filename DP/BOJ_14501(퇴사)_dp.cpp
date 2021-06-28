#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> t;
vector<int> p;
vector<int> dp;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int value1,value2;
		cin >> value1 >> value2;
		t.push_back(value1);
		p.push_back(value2);
		dp.push_back(value2);
	}
	dp.push_back(0);
	
	for (int i = n - 1; i >= 0; i--) {
		if (t[i] + i > n) //데드라인이 기한을 넘어가는경우
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
	}
	cout << dp[0] << '\n';
}