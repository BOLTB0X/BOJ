#include <iostream>
#include <queue>
using namespace std;

int n, k;
int dp[100001] = { 0, };

bool is_range(int x) {
	if (x < 0 || x>100000) 
		return false;
	return true;
}

int BFS(int start, int target) {
	queue<int> q;
	dp[n] = 1; //위치 방문처리
	q.push(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			return dp[cur]-1;
		}
		//범위 체크 및 그 곳이 미방문일 경우
		if (is_range(cur-1) && dp[cur - 1] == 0) {
			dp[cur - 1] = dp[cur] + 1;
			q.push(cur - 1);
		}
		if (is_range(cur + 1) && dp[cur + 1] == 0) {
			dp[cur + 1] = dp[cur] + 1;
			q.push(cur + 1);
		}
		if (is_range(cur * 2) &&  dp[cur * 2] == 0) {
			dp[cur * 2] = dp[cur] + 1;
			q.push(cur * 2);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	int ret = BFS(n, k);
	cout << ret << '\n';
	return 0;
}
