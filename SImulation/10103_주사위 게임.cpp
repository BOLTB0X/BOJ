#include<iostream>
#include<vector>

using namespace std;

pair<int, int> solution(int n, vector<pair<int, int>>& arr) {
	pair<int, int> answer = { 100,100 };

	for (auto& a : arr) {
		if (a.first > a.second)
			answer.second -= a.first;
		else if (a.first < a.second)
			answer.first -= a.second;
	}

	return answer;
}

int main(void) {
	int n;
	vector<pair<int, int>> arr;

	cin >> n;
	arr = vector<pair<int, int>>(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;

	pair<int, int> ret = solution(n, arr);
	cout << ret.first << '\n' << ret.second;

	return 0;
}