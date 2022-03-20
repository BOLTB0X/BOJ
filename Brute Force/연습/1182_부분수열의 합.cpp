#include <iostream>

using namespace std;

int result;
int arr[21];

// DFS
void DFS(int n, int s, int tot, int level) {
	// 배열을 넘어 간다면
	if (level == n)
		return;

	// 목표값 도달할 시
	if (tot + arr[level] == s) 
		result++; // 카운트
	
	DFS(n, s, tot, level + 1); // 현재를 건너 뛰기
	DFS(n, s, tot + arr[level], level + 1); // 현재 위치 더해주기
	
	return;
}

// 솔루션
int solution(int n, int s) {
	int answer = 0;
	result = 0;

	// DFS로 완전탐색 시작
	DFS(n, s, 0, 0);
	answer = result; // 카운트
	return answer;
}

int main(void) {
	int n, s;

	cin >> n >> s;

	for (int i = 0; i < n; ++i) // 원소 입력
		cin >> arr[i];

	int ret = solution(n, s);
	cout << ret;

	return 0;
}
