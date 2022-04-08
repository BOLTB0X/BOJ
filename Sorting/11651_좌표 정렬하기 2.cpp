#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

void solution(int n, vector<pair<int,int>>& arr) {
	//정렬
	sort(arr.begin(), arr.end(), compare);

	//출력만 바꿔서
	for (int i = 0; i < n; i++) 
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	
	return;
}

int main(void) {
	int n;
	cin >> n;

	// 벡터 초기화
	vector<pair<int,int>> arr(n);
	// 입력
	for (int i = 0; i < n; i++) 
		cin >> arr[i].first>> arr[i].second;

	solution(n, arr);
	return 0;
}
