#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<pair<int, int>>& v) {
	int answer = 0;
	int pack = 1001, one = 1001;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first < pack)
			pack = v[i].first;
		if (v[i].second < one)
			one = v[i].second;
	}

	if (pack < one * 6)
		answer += pack * (n / 6);
	else
		answer += one * (n / 6) * 6;
	n %= 6;

	if (pack > one * n)
		answer += n * one;
	else
		answer += pack;
	return answer;
}

int main(void) {
	int n, m;
	vector<pair<int, int>> v;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		v.push_back({ a,b });
	}

	int ret = solution(n, m, v);
	cout << ret;
	return 0;
}