#include <iostream>
#define Max_value (1e9+1)

using namespace std;

int max_result;
int min_result;
int arr[12]; // 숫자를 담을 배열

// 최댓값
int Max(int a, int b) {
	return a > b ? a : b;
}

// 최솟값
int Min(int a, int b) {
	return a < b ? a : b;
}

// DFS이용
void DFS(int n, int tot, int level, int plus, int minus, int mul, int div) {
	// 탈출 조건
	if (level == n) {
		max_result = Max(max_result, tot);
		min_result = Min(min_result, tot);
		return;
	}

	// 연산
	else {
		if (plus > 0)
			DFS(n, tot + arr[level], level + 1, plus - 1, minus, mul, div);
		if (minus > 0)
			DFS(n, tot - arr[level], level + 1, plus, minus - 1, mul, div);
		if (mul > 0)
			DFS(n, tot * arr[level], level + 1, plus, minus, mul - 1, div);
		if (div > 0)
			DFS(n, (int)tot / arr[level], level + 1, plus, minus, mul, div - 1);
	}
	return;
}

pair<int, int> solution(int n, int plus, int minus, int mul, int div) {
	pair<int, int> answer;

	// 초기값 셋팅
	max_result = -Max_value;
	min_result = Max_value;

	DFS(n, arr[0], 1, plus, minus, mul, div);

	answer.first = max_result;
	answer.second = min_result;
	return answer;
}

int main(void) {
	int n, plus, minus, mul, div;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cin >> plus >> minus >> mul >> div;

	pair<int,int> ret = solution(n, plus, minus, mul, div);
	cout << ret.first << '\n' << ret.second;
	
	return 0;
}
