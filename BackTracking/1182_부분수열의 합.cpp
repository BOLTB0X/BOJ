#include <iostream>

using namespace std;

int result = 0;
int arr[20];

void DFS(int n, int s, int idx, int tot) {
	// 탈출 조건
	if (idx == n)
		return;

	// 타겟넘버가 되면
	if (tot + arr[idx] == s) 
		result++;

	DFS(n, s, idx + 1, tot + arr[idx]);
	DFS(n, s, idx + 1, tot);
	return;
}

int solution(int n, int s) {
	int answer = 0;

	DFS(n, s, 0, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n, s;

	cin >> n >> s;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	int ret = solution(n, s);
	cout << ret;

	return 0;
}
