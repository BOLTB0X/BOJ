#include <iostream>
#include <vector>

using namespace std;

vector<int> tmp_LIS[1001];

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

vector<int> solution(int n, int* arr) {
	vector<int> answer;
	vector<int> dp(n + 1, 0);
	
	for (int i = 0; i < n; ++i) {
		tmp_LIS[i].push_back(arr[i]);
		dp[i] = 1;

		for (int j = i - 1; j >= 0; --j) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				tmp_LIS[i].clear();
				tmp_LIS[i] = tmp_LIS[j];
				tmp_LIS[i].push_back(arr[i]);
				dp[i] = dp[j] + 1;
			}
		}
		// 교체
		if (answer.size() < tmp_LIS[i].size())
			answer = tmp_LIS[i];
	}

	return answer;
}

int main(void) {
	int n;
	int arr[1001];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vector<int> ret = solution(n, arr);
	cout << ret.size() << '\n';
	for (int& r : ret)
		cout << r << ' ';
	return 0;
}