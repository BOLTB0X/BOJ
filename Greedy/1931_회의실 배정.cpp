#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100001];

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int solution(int n) {
	int answer = 1;
	
	// 끝나는 시간 기준으로 정렬
	sort(arr, arr + n, compare);
	int end = arr[0].second;

	// 그리디
	for (int i = 1; i < n; ++i) {
		if (arr[i].first >= end) {
			answer++;
			end = arr[i].second;
		}
	}
	
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		
		cin >> a >> b;
		arr[i] = { a,b };
	}

	int ret = solution(n);
	cout << ret;
	return 0;
}