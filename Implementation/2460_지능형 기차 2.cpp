#include <iostream>

using namespace std;

pair<int, int> arr[11];

int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(void) {
	int answer = arr[1].second; // 초기 값
	int cur = arr[1].second; // 현재

	for (int i = 2; i <= 10; ++i) {
		cur -= arr[i].first; // 현재 내린사람을 뺌
		cur += arr[i].second; // 현재 탄 사람들을 더해줌

		// 체크
		answer = Max(cur, answer);
	}

	return answer;
}

int main(void) {
	for (int i = 1; i <= 10; ++i) {
		// 내린 사람, 탄 사람 
		cin >> arr[i].first >> arr[i].second;
	}

	int ret = solution();
	cout << ret;

	return 0;
}